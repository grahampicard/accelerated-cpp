#include <algorithm> // next
#include <cctype>
#include <iostream>  // istream
#include <string>    // string
#include <string>
#include <system_error>  // logic_error
#include <vector>        // vector
#include <vector>

#include "grammar_exercise_list.h"
#include "string_split.h"

using std::domain_error;
using std::isspace;
using std::istream;
using std::logic_error;
using std::string;
using std::vector;
using std::next;

// Breaks a line of inputs into words, separated from each other by
// whitespace (space, tab, backspace, or EOF). It reads characters up to
// the whitespace character.
vector<string> split(const string& s) {
  // we'll start by defining a string
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;

  // invariant: we have processed characters [original value of i, i)
  while (i != s.size()) {
    // ignore leading blanks
    // invariant: characters in range [original i, current i) are all spaces
    while (i != s.size() && isspace(s[i])) ++i;

    // find end of next word
    string_size j = i;
    // invariant: none of the characters in the range [original j, current j)
    // is a space
    while (j != s.size() && !isspace(s[j])) ++j;

    // if we found some nonwhitespace characters
    if (i != j) {
      // copy from s starting at i and taking j - i chars
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }
  return ret;
}

int nrand(int n) {
  if (n <= 0 || n > RAND_MAX)
    throw domain_error("Argument to nrand is out of range");

  const int bucket_size = RAND_MAX / n;
  int r;

  do r = rand() / bucket_size;
  while (r >= n);
  return r;
}

bool bracketed(const string& s) {
  return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret) {
  if (!bracketed(word)) {
    ret.push_back(word);
  } else {
    // locate the rule that corresponds to word
    Grammar::const_iterator it = g.find(word);
    if (it == g.end()) throw logic_error("empty rule");

    // fetch the set of possible rules
    const Rule_collection& c = it->second;
  
    // from which we select one at random
    int n = nrand(c.size());
    Rule_collection::const_iterator ci = c.begin();
    next(ci,n);

    const Rule& r = *ci;

    // recursively expand the selected rule
    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
      gen_aux(g, *i, ret);
  }
}

vector<string> gen_sentence(const Grammar& g) {
  vector<string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}

// first step for the 7-0-3. It reads a category and an input value
// read a grammar from a given input stream
Grammar read_grammar(istream& in) {
  Grammar ret;
  string line;

  // read the input
  while (getline(in, line)) {
    // split the input into words
    vector<string> entry = split(line);
    if (!entry.empty())
      // use the category to store the associated rule
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
  }
  return ret;
}
