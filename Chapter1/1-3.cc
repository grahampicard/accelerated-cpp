// is this valid?

// looks fine. braces are execution blocks, and these blocks are valid
// expressions

#include <iostream>
#include <string>

int main() {
  {
    const std::string s = "a string";
    std::cout << s << std::endl;
  }

  {
    const std::string s = "another string";
    std::cout << s << std::endl;
  }

  return 0;
}