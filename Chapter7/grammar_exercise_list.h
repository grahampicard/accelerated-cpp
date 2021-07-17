#ifndef GUARD_grammar_exercise_h
#define GUARD_grammar_exercise_h

#include <istream>
#include <map>
#include <string>
#include <vector>
#include <list>

typedef std::list<std::string> Rule;
typedef std::list<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream& in);

int nrand(int n);

bool bracketed(const std::string& s);

void gen_aux(const Grammar& g, const std::string& word,
             std::vector<std::string>& ret);

std::vector<std::string> gen_sentence(const Grammar& g);

std::vector<std::string> split(const std::string& s);

#endif