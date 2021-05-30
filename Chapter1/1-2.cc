// Are the following definitions valid? Why or why not?
//     const std::string exclam = "!";
//     const std::string message = "Hello" + ", world" + exclam;

#include <iostream>
#include <string>

int main() {
  // message 1
  const std::string exclam = "!";
  const std::string message = "Hello" + ", world" + exclam;
  std::cout << message << std::endl;
  return 0;
}