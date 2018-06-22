#Prompt
Create three files: **my.h**, **my.cpp**, and **use.cpp**. The header file **my.h** contains

*extern int foo;
*void print_foo();
*void print(int);

The source code file **my.cpp #includes my.h** and **std_lib_facilities.h**, defines **print_foo()** to print the value of **foo**
using **cout**, and **print(int i)** to print the value of **i** using **cout**.
\tThe source code file **use.cpp #includes my.h**, defines **main()** to set value of **foo** to **7** and print it using **print_foo()**, and to print the value of **99** using **print()**. Note that **use.cpp** does not **#include std_lib_facilities.h** as it doesn't directly use any of those facilities.
\tGet these files compiled and run.
