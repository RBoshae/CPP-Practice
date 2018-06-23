# Drill 3

Write a program using a single file containing three namespaces X, Y, and Z so that the following Main() works correctly:
```
int Main()
{
  X::var = 7;
  X::print();   // print X's var
  using namespace Y;
  var = 9;
  print(); // print Y's var
  {
    using Z::var;
    using Z::print;
    var=11;
    print ();   // print Z's var
  }
  print();      // print Y's var
  X:: print();  // print X's var
}
```
Each namespace needs to define a variable called var and a function
called print() that outputs the appropriate var using cout.
