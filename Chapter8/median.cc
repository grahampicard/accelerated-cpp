#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>

using std::domain_error;
using std::sort;
using std::vector;

// compute the median of a vector<double>
double median(vector<double> vec) {
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0) throw domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double median_iter(vector<double>::const_iterator& first,
                  vector<double>::const_iterator& last) {

  int n = std::distance(first, last);

  if (first == last) throw domain_error("median of an empty vector");

  int mid = n / 2;

  std::advance(first, mid - 1);

  return n % 2 == 0 ? (*first++ + *first) / 2 : *++first;
}