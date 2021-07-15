#ifndef GUARD_gen_aux_h
#define GUARD_gen_aux_h

#include <string>
#include <vector>

#include "read_grammar.h"

using std::string;
using std::vector;

void gen_aux(const Grammar& g, const string& word, vector<string>& ret);

#endif