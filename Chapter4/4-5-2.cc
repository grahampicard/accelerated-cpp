#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "inputs.h"

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::vector;

int main() {
  // since we'll use size_type a lot, make a typedef.
  typedef vector<string>::size_type vec_sz;

  // input words
  vector<string> words;
  words = read(cin, words);

  // loop through words to find the word occurences
  vector<string> uniqueWords;
  vector<int> wordCounts;

  // get each words
  for (vec_sz i = 0; i < words.size(); ++i) {
    bool exists = false;
    for (vec_sz j = 0; j < wordCounts.size(); ++j) {
      if (words[i] == uniqueWords[j]) {
        wordCounts[j]++;
        exists = true;
        break;
      }
    }

    if (exists == false) {
      uniqueWords.push_back(words[i]);
      wordCounts.push_back(1);
    }
  }

  // print out results
  for (vec_sz i = 0; i < uniqueWords.size(); ++i) {
    cout << setw(10) << uniqueWords[i] << setw(10) << wordCounts[i] << endl;
  }
  return 0;
}
