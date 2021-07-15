#ifndef GUARD_gen_aux_h
#define GUARD_gen_aux_h

#include <list>
#include <string>

#include "read_grammar.h"

void gen_aux(const Grammar& g, const std::string& word,
             std::list<std::string>& ret);

#endif