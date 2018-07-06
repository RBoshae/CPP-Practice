#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {

  cout << "the size of char is" <<sizeof(char) <<''<< sizeof('a')<<'\n';
  cout << "the size of int is" <<sizeof(int)<<''<<sizeof(2+2)<<'\n';
  int* p = 0;
  cout<<"the size of int* is"<<sizeof(int*)<<''<<sizeof(p)<<'\n';

  // exteded example
  cout << "the size of bool is" <<sizeof(bool) <<''<<sizeof(true)<<'\n';
  cout << "the size of double is" <<sizeof(double)<<''<<sizeof(21.1)<<'\n';
  cout << "the size of vector<int> v(100) is"<<sizeof(std::vector<int> v(100))<<'\n';

  return 0;
}
