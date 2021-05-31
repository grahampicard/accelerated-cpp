// write a program to report the length of the longest and shortest string in
// its input list
//
// Pseudo:
//  1.  Create in `instream` to collect all input words.
//  2.  Create one vector for words, one for lengths
//  3.  For each input, loop through vector to see if word appears.
//      1.  If the word exists, pass.
//      2.  If the word doesn't extist, add it, add length to length counter.
//  4.  Loop through word vector and output all words, counts.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main() {
  string x;
  vector<string> words;
  vector<int> lengths;

  while (cin >> x) {
    bool wordExists = false;
    for (vector<string>::size_type i = 0; i < words.size(); ++i) {
      if (x == words[i]) {
        wordExists = true;
        break;
      }
    }

    if (wordExists == false) {
      int wordLength = x.length();
      words.push_back(x);
      lengths.push_back(wordLength);
    }
  }

  sort(lengths.begin(), lengths.end());

  vector<int>::size_type lastWordIdx = lengths.size() - 1;

  cout << "Longest word: " << lengths[lastWordIdx] << std::endl
       << "Shortest word " << lengths[0] << std::endl;

  return 0;
}
