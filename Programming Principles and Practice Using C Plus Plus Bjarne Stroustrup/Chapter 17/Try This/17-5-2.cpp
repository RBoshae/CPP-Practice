#include <iostream>
#include <string>

class Dog {
  int age;
  std::string name;
public:
  Dog(){
    age = 0;
    name = "Random stray";
    std::cout << name << ": Woof!\n";
  }
  Dog(std::string n){
    age = 0;
    name = n;
    std::cout << name << ": Woof!\n";
  }
  ~Dog() {
    std::cout << name << " ran away!\n";
  }
};

void foo() {
  std::cout << "entered foo()\n";
  std::cout << "Declaring Dog Dove\n";
  Dog dove("Dove");
  std::cout << "exiting foo()\n";

  return;
}

void bar() {
  std::cout << "entered bar\n";
  std::cout << "Declaring Dog Bowser\n";
  Dog* bowser = new Dog("Bowser");
  delete bowser;
  std::cout << "exiting bar()\n";
  return;
}

int main(int argc, char const *argv[]) {
  std::cout << "In main\n";

  foo();

  std::cout << "Declaring Dog Rover\n";
  Dog rover("Rover");

  std::cout << "Declaring random Dog\n";
  Dog* stray = new Dog;
  bar();

  delete stray;

  return 0;
}
