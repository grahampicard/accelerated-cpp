// write a program to count how many times each distinct word appears in its
// list
//
// Pseudo:
//  1.  Create in `instream` to collect all input words.
//  2.  Create two vectors: words, and counts.
//  3.  For each word, loop through words vector.
//      1.  If the word exists, increment the count vector at the same index.
//      2.  If the word doesn't extist, add it to the end, and increment the
//      count index.
//  4.  Loop through word vector and output all words, counts.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main() {
  string x;
  vector<string> words;
  vector<int> counts;

  std::cout << "Enter in a list of words, sepearated by a new line, then EOF: ";

  // perform input
  while (std::cin >> x) {
    bool wordExists = false;
    for (vector<string>::size_type i = 0; i < words.size(); ++i) {
      // Once the word is found, increment and break
      if (x == words[i]) {
        counts[i]++;
        wordExists = true;
        break;
      }
    }

    if (wordExists == false) {
      words.push_back(x);
      counts.push_back(1);
    }
  }

  // print outputs
  std::cout << "Word"
            << "\t"
            << "Count" << std::endl
            << "----"
            << "\t"
            << "-----" << std::endl;

  for (vector<string>::size_type i = 0; i < words.size(); ++i) {
    std::cout << words[i] << "\t" << counts[i] << std::endl;
  }

  return 0;
}
