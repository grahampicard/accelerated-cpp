#include <string>
#include <vector>

#include "gen_aux.h"
#include "read_grammar.h"

using std::string;
using std::vector;

vector<string> gen_sentence(const Grammar& g) {
  vector<string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}
