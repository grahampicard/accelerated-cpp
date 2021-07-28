#include "8-4.h"

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{0, 10, 20, 30, 40};
  std::vector<int> vec2{0, 10, 20, 30, 40};

  myreverse(vec.begin(), vec.end());
  myreverse2(vec2.begin(), vec2.end());

  for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i) {
    std::cout << *i << std::endl;
  }

  std::cout << std::endl;

  for (std::vector<int>::iterator i = vec2.begin(); i != vec2.end(); ++i) {
    std::cout << *i << std::endl;
  }

  return 0;
}