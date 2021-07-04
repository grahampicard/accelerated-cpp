// Write a function named center(const vector<string>&) that returns a picture
// in which all the lines of the original picture are padded out to their full
// width, and the padding is as evenly divided as possible between the left
// and right sides of the picture. What are the properties of pictures for
// which such a function is useful? How can you tell whether a given picture
// has these properties?
// 
// sample input:
//  one, two, three, four
//
// expected result
// *  one  *
// *  two  *
// * three *
// * four  *

// pseudo
//  1.  iterate through each item of the string
//  2.  find the maximum string length
//  3.  iterate again through each item, and pad it by
//      the MAX - val / 2 on the left & right (if it's not even, then make the 
//      left side have one less)
//  4.  print the image
//  5.  return 0

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::string;
using std::vector;

string center(const vector<string>& v) {
  vector<string>::size_type max_str = 0;
  const vector<string>::size_type padding = 1;
  string result = "";

  // find the maximum length
  for (vector<string>::const_iterator s = v.begin(); s != v.end(); ++s) {
    max_str = max(s->length(),max_str);
  }

  const vector<string>::size_type max_len = max_str + 2 * padding;

  for (vector<string>::size_type i = 0; i < max_len + 2; ++i) {
    result.append("*");
  }
  result.append("\n");

  // iterate through, and print picture based 
  for (vector<string>::const_iterator s = v.begin(); s != v.end(); ++s) {
    vector<string>::size_type cur_len = max_len - s->length();
    result.append("*");

    for (vector<string>::size_type i = 0; i < cur_len / 2; ++i) {
      result.append(" ");
    }
    result.append(*s);
    for (vector<string>::size_type i = cur_len; i > cur_len / 2; --i) {
      result.append(" ");
    }
    result.append("*\n");
  }

  for (vector<string>::size_type i = 0; i < max_len + 2; ++i) {
    result.append("*");
  }
  result.append("\n");  

  return result;

}

int main() {
  string x;
  vector<string> words;

  while (cin >> x) {
      words.push_back(x);
  }

  string res = center(words);
  cout << res << endl;
  return 0;
}

