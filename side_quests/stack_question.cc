// “ab2[cd]”-> “abcdcd”
// “ab2[v3[a]f]” -> abvaaafvaaaf

// Any a-z not in a capture group gets mapped to output directly
// Any number preceding a capture group identifies how many times the capture
// group will be repeated Capture group is encapsulated by []

// Pseudo:
// Create a stack (list/vector) to contain all the elements
// Create a sentence that contains the end string
// Push the entire string to the stack
// Pop the word, scan for numeric & capture group, push the interior into the
// stack the appropriate # of times Push the remaining part of the sentence too
// If numeric
// Find the end of the number
// Find the capture group
// Push the capture group deeper
// Push the interior deeper into the stack

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stoi;

void parse(string& s, string& sentence, vector<string>& stack) {
  string repetitions;
  vector<string>::size_type string_length = s.length(), i = 0;
  while (i < string_length) {

    // Define the curent letter
    const char si = s[i];

    // first, write to the string if it's not bracketed
    if (isalpha(si)) { 
      sentence.push_back(si);
    }

    // if it's a number, put it in the repetitions string
    if (isdigit(si)) {
      repetitions.push_back(si);
    }

    // if it's a bracket, start the process for detecthing the end
    if (si == '[') {
      int brackets = 1;
      string pattern;
      int reps = stoi(repetitions);

      // start another iterator looking for the pattern
      vector<string>::size_type j = i + 1;
      while (j < string_length) { 
        const char pattern_string = s[j];

        if (pattern_string == '[')
          brackets += 1;
        if (pattern_string == ']') {
          brackets -= 1;
          if (brackets == 0) {
            string remainder;
            for (++j; j < string_length; ++j) {
              remainder.push_back(s[j]);
            }
            stack.push_back(remainder);
            for (int i = 0; i < reps; ++i) {
              stack.push_back(pattern);
            }
            return;
          }
        }
        ++j;
        pattern.push_back(pattern_string);
      }
    }
    ++i;
  }
  return;  
}

int main() {
  string myInput = "ab2[v3[a]f]";
  string sentence;
  vector<string> stack;
  stack.push_back(myInput);

  while (!stack.empty()) {
    string current = stack.back();
    stack.pop_back();
    parse(current, sentence, stack);
  }

  cout << sentence << endl;
  return 0;
}
