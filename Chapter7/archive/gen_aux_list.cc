#include <list>
#include <string>
#include <system_error>

#include "bracketed.h"
#include "nrand.h"
#include "read_grammar.h"

using std::list;
using std::logic_error;
using std::string;

void gen_aux(const Grammar& g, const string& word, list<string>& ret) {
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