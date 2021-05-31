#include <cmath>
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::log10;
using std::setw;

int main() {
  int max = 100;
  int colsize = log10(max * max) + 1;

  for (int i = 1; i < max; ++i) {
    cout << setw(colsize) << i << setw(colsize) << i * i << endl;
  }

  return 0;
}
