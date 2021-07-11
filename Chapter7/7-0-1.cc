// Introducing maps
// (S7.2 / 124)

#include <iostream> // cin, cout, endl
#include <map>      // map
#include <string>   // string

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    string s;
    map<string, int> counters; // store each word and an associated counter

    // read the input, keeping track of each word
    while (cin >> s)
        ++counters[s];

    // write the words and associated counts
    for (map<string, int>::const_iterator it = counters.begin();
         it != counters.end(); ++it)
    {
        // each element of the map is a `pair`, that has two values
        // `first` and `second`. These are functionally equivalent
        // to keys and values in Python dicts.
        cout << it->first << "\t"
             << it->second << endl;
    }
    return 0;
}