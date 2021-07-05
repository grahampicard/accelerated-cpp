// Section 6-1-2: Finding URLs
// Pages: 105-110
//
// Finds the URLs

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::find_if;
using std::string;
using std::vector;

// this function checks to see if a character is one that is not allowed
// in the URL
bool not_url_char(char c)
{
  // characters, in addition to alphanumerics, that can appear in a URL
  static const string url_ch = "~;/?:@=&$-_.+!*`(),";

  // see whether c can appear in a URL and return the negative
  return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

// Checks to find the end of a URL.
string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
  return find_if(b, e, not_url_char);
}

// finds the beginning of a URL
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
  static const string sep = "://";

  typedef string::const_iterator iter;

  // i marks where the separator was found
  iter i = b;

  // uses `search` which finds iterators that uses a sequence of inputs and a
  // sequence of outputs
  while ((i = search(i, e, sep.begin(), sep.end())) != e)
  {
    // make sure the separator isn't at the beginning of hte line
    if (i != b && i + sep.size() != e)
    {
      // beg marks the beginning of the protocol name
      iter beg = i;
      while (beg != b && isalpha(beg[-1]))
        --beg;

      // is there at least one appropriate character before and after the sep
      if (beg != i && !not_url_char(i[sep.size()]))
        return beg;
    }

    // the separator we found wasn't part of a URL; advance i past this separator
    i += sep.size();
  }
  return e;
}

vector<string> find_urls(const string &s)
{
  vector<string> ret;
  typedef string::const_iterator iter;
  iter b = s.begin(), e = s.end();

  // look through the entire input
  while (b != e)
  {
    // look for one or more letters followed by ://
    b = url_beg(b, e);

    // if we find it
    if (b != e)
    {
      iter after = url_end(b, e);

      // remember the URL
      ret.push_back(string(b, after));

      // advance b and check for more URLs on the line
      b = after;
    }
  }
  return ret;
}

int main()
{
  string testStr = "okay let's see http://google.com does it work? or http://yahoo.com is one?";
  vector<string> ret = find_urls(testStr);

  for (vector<string>::iterator i = ret.begin(); i != ret.end(); ++i)
  {
    cout << *i << endl;
  }
}