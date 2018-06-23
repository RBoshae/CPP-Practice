#include "swap.h"
#include <iostream>
using namespace std;
int main() {

  int x = 7;
  int y = 9;
  swap_v(x,y);  // x is still 7, y is still 9
  cout << "Values of x,y after calling swap_v(x,y)" << x << " " << y << endl;

  swap_v(7,9);  // won't compile because 7 and 9 are not variables


  swap_r(x,y);  // x is 9, y is 7
  cout << "Values of x,y after calling swap_r(x,y)" << x << " " << y << endl;

  // swap_r(7,9);  // won't compile since 7 and 9 are not references.
  // cout << "Values of x,y after calling swap_r(x,y)" << x << " " << y << endl;


  const int cx = 7;
  const int cy = 9;

  swap_v(cx,cy); // Copies are passed in but no changes to cx and cy is made
  cout << "Values of cx,cy after calling swap_v(cx,cy)" << cx << " " << cy << endl;

  // swap_r(cx,cy);  // Should result in compiler error since cx and cy are read only references
  // cout << "Values of cx,cy after calling swap_r(cx,cy)" << cx << " " << cy << endl;

  double dx = 7.7;
  double dy = 9.9;

  swap_v(dx,dy); // type mismatch won't compile
  cout << "Values of dx,dy after calling swap_v(dx,dy)" << dx << " " << dy << endl;

  // swap_r(dx,dy); // type mismatch won't compile
  // cout << "Values of dx,dy after calling swap_r(dx,dy)" << dx << " " << dy << endl;

  // swap_r(dx,dy);
  // cout << "Values of dx,dy after calling swap_r(dx,dy)" << dx << " " << dy << endl;


}
