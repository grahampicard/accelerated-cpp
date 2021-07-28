// (S1.1 / 1)
// compile all programs in the chapter
// ask for a person's name, and greet the person
#include <iostream>
#include <string>

int main() {
  // ask for hte person's name
  std::cout << "Please enter your first name: ";

  // read the name
  std::string name;  // define name
  std::cin >> name;  // read into name

  // write a greeting
  std::cout << "Hello, " << name << "!" << std::endl;
  return 0;
}