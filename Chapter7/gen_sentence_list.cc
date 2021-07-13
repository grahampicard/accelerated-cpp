#include <string>
#include <list>

#include "gen_aux_list.h"
#include "read_grammar.h"

using std::string;
using std::list;

list<string> gen_sentence(const Grammar& g) {
  list<string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}
