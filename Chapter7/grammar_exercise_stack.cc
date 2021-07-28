#include <iostream>      // istream
#include <string>        // string
#include <system_error>  // logic_error
#include <vector>        // vector

#include "grammar_exercise_stack.h"
#include "string_split.h"

using std::domain_error;
using std::istream;
using std::logic_error;
using std::string;
using std::vector;

int nrand(int n) {
  if (n <= 0 || n > RAND_MAX)
    throw domain_error("Argument to nrand is out of range");

  const int bucket_size = RAND_MAX / n;
  int r;

  do r = rand() / bucket_size;
  while (r >= n);
  return r;
}

// any bracketed word is a Rule identifier and is detected by this function.
bool bracketed(const string& s) {
  return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}


void gen_aux(const Grammar& g, const string& token,
             vector<string>& sentence, vector<string>& tokens) {
  if (!bracketed(token)) {
    sentence.push_back(token);
  } else {
    Grammar::const_iterator it = g.find(token);
    if (it == g.end()) throw logic_error("empty rule");

    // fetch the set of possible rules
    const Rule_collection c = it->second;

    // choose one at random
    const Rule& r = c[nrand(c.size())];

    // push these back on the stack
    for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
      tokens.push_back(*i);
  }
}

vector<string> gen_sentence(const Grammar& g) {
  vector<string> sentence;
  vector<string> tokens;

  tokens.push_back("<sentence>");

  while (!tokens.empty()) {
    string token = tokens.back();
    tokens.pop_back();
    gen_aux(g, token, sentence, tokens);
  }
  return sentence;
}


// first step for the 7-0-3. It reads a category and an input value
// read a grammar from a given input stream
// here's the structure of a Grammar
//   std::map<
//     std::string, 
//     std::vector<    // Rule_Collection
//       std::vector<  // Rule
//       std::string
//       >
//     >
//   > Grammar;

Grammar read_grammar(istream& in) {
  Grammar ret;
  string line;

  // read the input
  while (getline(in, line)) {
    // split the input into words
    vector<string> entry = split(line);
    if (!entry.empty())
      // use the category to store the associated rule
      // e.g. entry[0] == "<noun>"
      //      entry[1] == "cat"
      //      entry[2] == "nip"
      // So each rule consists of a word or a word phrase
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));

  }
  return ret;
}
