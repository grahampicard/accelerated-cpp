#include <cmath>
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::log10;
using std::setw;

int main() {
  double max_val = 100;
  int colsize = log10(max_val * max_val) + 1;

  for (double i = 1; i < max_val; ++i) {
    cout << setw(colsize) << i << setw(colsize) << i * i << endl;
  }

  return 0;
}
