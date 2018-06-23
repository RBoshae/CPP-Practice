#include "my.h"
// NOTE: use.cpp does not use #include std_lib_facilities.h as
//       it doesn't directly use any of those facilities.

int foo; // Global declaration.

int main() {
  foo = 7;

  print_foo();

  print(99);

  return 0;
}
