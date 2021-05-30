// is this valid? What if we change }} to };} in the third line from the end

// should be fine. the second statement is scoped within the first

#include <iostream>
#include <string>

int main() {
  {
    std::string s = "a string";
    {
      std::string x = s + ", really";
      std::cout << s << std::endl;
    }
  }
  return 0;
}