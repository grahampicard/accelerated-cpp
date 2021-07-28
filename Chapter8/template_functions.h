#ifndef GUARD_template_functions_h
#define GUARD_template_functions_h

#include <algorithm>  // sort
#include <iostream>   // stdio
#include <stdexcept>  // domain_error
#include <string>     // string
#include <vector>     // vector

using std::domain_error;
using std::find_if;
using std::sort;
using std::string;
using std::swap;
using std::vector;

// (S8.1.1 / 141)
//
// In this template, `T` is the templated class which will be returned
// by the median function
template <class T>
T median(vector<T> v) {
  typedef typename vector<T>::size_type vec_sz;

  vec_sz size = v.size();
  if (size == 0) throw domain_error("median of an empty vector");

  sort(v.begin(), v.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

// (S8.1.3 / 143)
template <class T>
T max(const T& left, const T& right) {
  return left > right ? left : right;
}

// (S8.2.2 / 145)
template <class In, class X>
In find(In begin, In end, const X& x) {
  while (begin != end && *begin != x) ++begin;
  return begin;
}

// (S8.2.3 / 146)
template <class In, class Out>
Out copy(In begin, In end, Out dest) {
  while (begin != end) *dest++ = *begin++;
  return dest;
}

// (S8.2.4 / 147)
template <class For, class X>
void replace(For beg, For end, const X& x, const X& y) {
  while (beg != end) {
    if (*beg == x) *beg = y;
    ++beg;
  }
}

// (S8.2.5 / 148)
template <class Bi>
void reverse(Bi begin, Bi end) {
  while (begin != end) {
    --end;
    if (begin != end) swap(*begin++, *end);
  }
}

// (S8.2.6 / 148)
template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x) {
  while (begin < end) {
    // find the midpoint of the range
    Ran mid = begin + (end - begin) / 2;
    // see which part of hte range contains x; keep looking only in that part
    if (x < *mid)
      end = mid;
    else if (*mid < x)
      begin = mid + 1;
    // if we got here, then *mid == x so we're done
    else
      return true;
  }
  return false;
}

// (S8.4 / 152)
bool space(char c) { return isspace(c); }

bool not_space(char c) { return !isspace(c); }

template <class Out>
void split(const string& str, Out os) {
  typedef string::const_iterator iter;
  iter i = str.begin();

  while (i != str.end()) {
    // ignore leading blanks
    i = find_if(i, str.end(), not_space);

    // find the rest of the word
    iter j = find_if(i, str.end(), space);

    // copy the characters in [i, j)
    if (i != str.end()) *os++ = string(i, j);

    i = j;
  }
}

#endif