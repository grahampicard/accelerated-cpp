#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "string_split.h"

// Write a program to write the lowercase words in the input followed by the
// uppercase words.
int main() {
  std::string s = "One two Three four";
  std::vector<std::string> vs = split(s);
  std::vector<std::string> uppercase;

  for (std::vector<std::string>::iterator i = vs.begin(); i != vs.end(); ++i) {
    std::string a = *i;
    if (std::islower((*i)[0])) {
      std::cout << *i << std::endl;
    } else
      uppercase.push_back(*i);
  }

  for (std::vector<std::string>::iterator i = uppercase.begin();
       i != uppercase.end(); ++i) {
    std::cout << *i << std::endl;
  }

  return 0;
}