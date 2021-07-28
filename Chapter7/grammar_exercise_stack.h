#ifndef GUARD_grammar_exercise_h
#define GUARD_grammar_exercise_h

#include <istream>
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream& in);

int nrand(int n);

bool bracketed(const std::string& s);

void gen_aux(const Grammar& g, const std::string& token,
             std::vector<std::string>& sentence,
             std::vector<std::string>& tokens);

std::vector<std::string> gen_sentence(const Grammar& g);

#endif