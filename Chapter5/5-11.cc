#include <iostream>
#include <string>
#include <vector>

// Write a program to determine if a word has any ascenders or descenders.
// Find the longest word in a dictionary that has neither ascenders nor
// descenders.

typedef std::vector<std::string> str_vec;

int main()
{
  str_vec dictionary;
  std::string ascenders = "bdfhkl";
  std::string descenders = "gjpqy";

  // input dict (separated by " ") and read into a vector
  while (std::cin)
  {
    std::string s;
    std::cin >> s;
    dictionary.push_back(s);
  }

  str_vec noAscendersDescenders;

  // iterate through each word
  for (str_vec::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
  {
    bool noAscenders = true;
    bool noDescenders = true;

    // go through each letter
    for (std::string::iterator letter = i->begin(); letter != i->end(); ++letter)
    {
      // first check ascenders
      for (std::string::iterator j = ascenders.begin(); j != ascenders.end(); ++j)
      {
        if (*letter == *j)
          noAscenders = false;
      }
      // next check descenders
      for (std::string::iterator j = descenders.begin(); j != descenders.end(); ++j)
      {
        if (*letter == *j)
          noDescenders = false;
      }
    }

    if (noAscenders && noDescenders)
      noAscendersDescenders.push_back(*i);
  }

  // find longest word
  std::string::size_type max_len = 0;
  std::string max_word;

  for (str_vec::iterator i = noAscendersDescenders.begin(); i != noAscendersDescenders.end(); ++i)
  {
    if (i->size() > max_len)
    {
      max_len = i->size();
      max_word = *i;
    }
  }

  std::cout << max_word << std::endl;
}