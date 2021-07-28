#include <iostream>      // istream
#include <string>        // string
#include <system_error>  // logic_error
#include <vector>        // vector

#include "grammar_exercise_nrand.h"
#include "string_split.h"
#include "math.h"

using std::domain_error;
using std::istream;
using std::logic_error;
using std::string;
using std::vector;
using std::ceil;

#define MY_RAND_MAX = 32767

// reimplement using an arbitrarily large N

int nrand(int n) {
  if (n <= 0 )
    throw domain_error("Argument to nrand is out of range");

  int r;

  if (n <= MY_RAND_MAX) {
    const int bucket_size = MY_RAND_MAX / n;

    do {
      int bucket = rand() / bucket_size;
      r = bucket;
    } while (r >= n);
  } else {
    const int bucket_size = ceil(n / MY_RAND_MAX);

    do {
      const int bucket = nrand(MY_RAND_MAX);
      const int remainder = nrand(bucket_size);
      r = (bucket - 1) * bucket_size + remainder;
    } while (r >= n);
  } 
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
    const Rule& r = c[nrand(c.size())];

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
