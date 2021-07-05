// Section 6-1-2: Palindromes
// Pages: 105
//
// Uses `equal` algorithm, which also leverages iterators
// to reimplement our palindrome function created in earlier chapters

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::equal;
using std::string;
using std::vector;

bool is_palindrome(const string &s)
{
  return equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
  vector<string> words{"equal", "level", "bevel", "madam"};

  if (is_palindrome(words[0]) == true)
    return -1;

  if (is_palindrome(words[1]) == false)
    return -1;

  if (is_palindrome(words[2]) == true)
    return -1;

  if (is_palindrome(words[3]) == false)
    return -1;

  cout << "Passed" << endl;
  return 0;
}