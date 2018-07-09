#include <iostream>
#include <string>

using namespace std;

struct Link {
  string value;
  Link* prev;
  Link* succ;
  Link(const string& v, Link* p=0, Link* s=0) : value(v), prev(p), succ(s){}
};

Link* insert(Link* p, Link* p) // insert n before p (incomplete)
{
  n->succ = p;  // p comes after n
  p->prev->succ = n; // n comes after what used to be p's predecessor
}

int main(int argc, char const *argv[]) {
  Link* norse_gods = new Link("Thor",0,0);
  norse_gods = new Link("Odin", norse_gods, 0);
  norse_gods->succ->prev = norse_gods;
  norse_gods = new Link("Freia", norse_gods, 0);
  norse_gods->succ->prev = norse_gods;

  return 0;
}
/* code */
