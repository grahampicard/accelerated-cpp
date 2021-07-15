#ifndef GUARD_gen_sentence_list_h
#define GUARD_gen_sentence_list_h

#include <list>
#include <string>

#include "read_grammar.h"

std::list<std::string> gen_sentence(const Grammar& g);

#endif