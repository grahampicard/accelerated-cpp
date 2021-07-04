#include <iostream>
#include <string>
#include <vector>

#include "string_split.h"

typedef std::vector<std::string> str_vec;

// Palindromes are wordds that are spelled the same right to left as left to
// right. Write a program to find all the palindromes in a dictionary. Next
// find the longest palindrome.

int main()
{
  str_vec dictionary;

  while (std::cin)
  {
    std::string rawInput;
    std::cin >> rawInput;
    dictionary.push_back(rawInput);
  }

  str_vec palindromes;

  for (str_vec::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
  {
    std::string cur_word = *i;
    bool isPalindrome = true;
    for (str_vec::size_type k = 0; k * 2 <= cur_word.size(); ++k)
    {
      str_vec::size_type l = cur_word.size() - k - 1;

      if (cur_word[k] != cur_word[l])
      {
        isPalindrome = false;
        break;
      }
    }
    if (isPalindrome)
    {
      palindromes.push_back(cur_word);
    }
  }

  std::string::size_type max_len = 0;
  std::string max_palindrome;
  for (str_vec::iterator i = palindromes.begin(); i != palindromes.end(); ++i)
  {
    if (i->size() > max_len)
    {
      max_palindrome = *i;
      max_len = i->size();
    }
  }
  std::cout << max_palindrome << std::endl;
  return 0;
}