#include "swap.h"

void swap_v(int a, int b){
  int temp;
  temp = a;
  a=b;
  b = temp;
}

void swap_r(int& a, int& b) {
  int temp;
  temp = a;
  a=b;
  b = temp;
}

// NOTE: swap_cr(const int& a, const int& b) will not compile because a and b are read only references. 
// void swap_cr(const int& a, const int& b)
// {
//   int temp;
//   temp = a;
//   a=b;
//   b = temp;
// }
