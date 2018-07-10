#include <iostream>
using namespace std;

class MyLinkedList {
public:
    struct Node {
        Node* next;
        Node* prev;
        int val;
    };

    Node* head;

    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0) return -1;

        Node* curr = head;
        for(int i = 0; i < index; ++i) {
            if (curr->next!=0) {
                curr = curr->next;
            } else {
                return -1;
            }
        }
        return curr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

        if (head == NULL) {
            head = new Node();
            head->val=val;
        } else {
            Node* curr = new Node();
            curr->val = val;
            curr->next = head;
            head->prev = curr;
            head = curr;
        }
        return;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* curr = new Node();
        curr->val = val;

        Node* tail = head;
        // find last node in MyLinkedList
        while(tail->next!=0) {
            tail = tail->next;
        }
        curr->prev = tail;
        tail->next = curr;

        return;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        // head case
        if (index==0) {
            this->addAtHead(val);
        } else {
            Node* curr = head;
            for(int i = 0; i < index; i++) {
                if (curr->next != 0) {
                    curr = curr->next;
                } else {
                  // tail case
                  if (index==(i+1)) {
                    this->addAtTail(val);
                    return;
                  }
                  cout << "End of linked list did not add.";
                  return;
                }
            }
            cout << "HERE";

            // middl case
            // curr is where we want to emplace our new node
            Node* linkToAdd = new Node();
            linkToAdd->val = val;
            linkToAdd->prev = curr->prev;
            linkToAdd->next = curr;
            curr->prev->next=linkToAdd;
            curr->prev=linkToAdd;

        }

        return;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node* curr = head;

        // head case
        if (index==0) {
            head = head->next;
            delete curr;
        } else {

            for (int i = 0 ; i < index; ++i) {
                if (curr->next !=0) {
                    curr=curr->next;
                } else {
                    return;
                }
            }



            // tail case
            if (curr->next == 0) {
                curr->prev->next = 0;
                delete curr;
            }
            // middle case
            else {
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
                delete curr;
            }

        }


    }

    void print() {
      Node* curr = head;
      while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
      }
      cout << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

int main(int argc, char const *argv[]) {
  MyLinkedList obj;
  cout << "Adding 1 to head. Result: ";
  obj.addAtHead(1);
  obj.print();

  // cout << "Adding 3 to tail. Result: ";
  // obj.addAtTail(3);
  // obj.print();

  // cout << "Adding 2 at index 1. Result: ";
  // obj.addAtIndex(1,2);
  // obj.print();

  cout << "Adding 2 at index 1. Result: ";
  obj.addAtIndex(1,2);
  obj.print();


  cout << "other results: ";
  cout << obj.get(1);
  // obj.deleteAtIndex(1);
  cout << obj.get(0);
  cout << obj.get(2);

  return 0;
}
