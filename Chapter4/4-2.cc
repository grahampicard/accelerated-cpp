#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::setw;

int main() {
  int colsize = 10;

  cout << setw(colsize) << "i" << setw(colsize) << "i^2" << endl << endl;

  for (int i = 1; i <= 100; ++i) {
    cout << setw(colsize) << i << setw(colsize) << i * i << endl;
  }

  return 0;
}