#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> str_vec;

int main() {
  str_vec words{"parallax", "ecce", "loop", "mayam"};

  for (str_vec::iterator i = words.begin(); i != words.end(); ++i) {
    std::string cur_word = *i;

    for (std::string::iterator j = cur_word.begin(); j != cur_word.end(); ++j) {
      std::cout << *j;
    }
  }
}