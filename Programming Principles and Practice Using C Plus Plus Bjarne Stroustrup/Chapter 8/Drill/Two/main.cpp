#include "swap.h"
int main() {
  int x = 7;
  int y = 9;
  swap_v(x,y);
  cout << "Values of x,y after calling swap_v(x,y)" << x << " " << y << endl;

  swap_v(7,9);
  cout << "Values of x,y after calling swap_v(x,y)" << x << " " << y << endl;

  swap_r(x,y);
  cout << "Values of x,y after calling swap_r(x,y)" << x << " " << y << endl;

  swap_r(7,9);
  cout << "Values of x,y after calling swap_r(x,y)" << x << " " << y << endl;

  const int cx = 7;
  const int cy = 9;

  swap_v(cx,cy);
  cout << "Values of cx,cy after calling swap_v(cx,cy)" << cx << " " << cy << endl;

  swap_v(7,9);
  cout << "Values of cx,cy after calling swap_v(cx,cy)" << cx << " " << cy << endl;

  swap_r(cx,cy);
  cout << "Values of cx,cy after calling swap_r(cx,cy)" << cx << " " << cy << endl;

  swap_r(7,9);
  cout << "Values of cx,cy after calling swap_r(cx,cy)" << cx << " " << cy << endl;

  double dx = 7.7;
  double dy = 9.9;

  swap_v(dx,dy);
  cout << "Values of dx,dy after calling swap_v(dx,dy)" << dx << " " << dy << endl;

  swap_v(7,9);
  cout << "Values of dx,dy after calling swap_v(dx,dy)" << dx << " " << dy << endl;

  swap_r(dx,dy);
  cout << "Values of dx,dy after calling swap_r(dx,dy)" << dx << " " << dy << endl;

  swap_r(dx,dy);
  cout << "Values of dx,dy after calling swap_r(dx,dy)" << dx << " " << dy << endl;


}
