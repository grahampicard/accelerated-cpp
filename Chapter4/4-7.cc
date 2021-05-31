#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  vector<double> results;
  double x;
  while (cin >> x) results.push_back(x);

  double sum;
  vector<double>::size_type count = results.size();

  for (vector<double>::size_type i = 0; i < count; ++i) {
    sum += results[i];
  }

  cout << "Average: " << sum / count << endl;
}
