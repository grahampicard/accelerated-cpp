// Generating sentences
// (S7.4 / xxx)

#include <iostream>
#include <list>
#include <string>

#include "gen_sentence_list.h"
#include "read_grammar.h"

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

int main() {
  // generate the sentenc
  list<string> sentence = gen_sentence(read_grammar(cin));

  // write the first word, if any
  list<string>::const_iterator it = sentence.begin();
  if (!sentence.empty()) {
    cout << *it;
    ++it;
  }

  // write the rest of the words, each preceded by a space
  while (it != sentence.end()) {
    cout << " " << *it;
    ++it;
  }
  cout << endl;
  return 0;
}
