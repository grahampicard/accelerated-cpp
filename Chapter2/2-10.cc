#include <iostream>
#include <string>

int main() {
  int k = 0;
  while (k != 10) {
    // this makes cout availalbe in our local namespace.
    using std::cout;
    cout << "*";
    ++k;
  }
  // this is standard declaration
  std::cout << std::endl;
  return 0;
}