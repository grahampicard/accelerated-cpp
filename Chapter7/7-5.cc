// Reimplement the gen_sentence program using two vectors. One will fully
// unwound, generated sentence, and the other will hold the rules and be
// used as a stack. Do not use any recursive calls.
//
// Generating sentences
// (S7.4 / xxx)

#include <iostream>
#include <string>
#include <vector>

#include "grammar_exercise_list.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  // generate the sentenc
  vector<string> sentence = gen_sentence(read_grammar(cin));

  // write the first word, if any
  vector<string>::const_iterator it = sentence.begin();
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
