// Reimpliment the frame and hcat functions using iterators
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::max;
using std::string;
using std::vector;

string::size_type width(const vector<string> &v)
{
  string::size_type maxlen = 0;
  for(vector<string>::const_iterator i = v.begin(); i != v.end(); ++i) 
    maxlen = max(maxlen, i->size());
  return maxlen;
}

vector<string> frame(const vector<string> &v)
{
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');

  // write hte top border
  ret.push_back(border);

  // write each interior row, bordered by an astrisk and a space
  for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i)
  {
    ret.push_back("* " + (*i) + string(maxlen - i->size(), ' ') + " *");
  }
  ret.push_back(border);
  return ret;  
}


vector<string>
hcat(const vector<string>& left, const vector<string>& right)
{
  vector<string> ret;

  // add 1 to leave a space between pictures
  string::size_type width1 = width(left) + 1;

  // indices to look at elements from left and right respectively
  vector<string>::const_iterator i = left.begin(), j = right.begin();
  string s;

  // continue until we've seen all rows from both pictures
  while (i != left.end() || j != right.end()) {
    // construct new string to hold characters
    string s;
    
    // copy a row from the left-hand side
    if (i != left.end())
      s = *(i++);

    // pad to full width
    s += string(width1 - s.size(), ' ');

    // copy a row from the right-hand side, if there is one
    if (j != right.end())
      s += *(j++);

    // add s to the picture we're creating
    ret.push_back(s);
  }
  return ret;
}

int vectorOut(const vector<string>& v) {
  for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i) {
    cout << *i << endl;
  }
  return 0;
}

int main()
{
    string s;            // line
    vector<string> p;    // paragraph
 
    // read multiple lines to make a paragraph
    while (getline(cin, s))
        p.push_back(s);
 
    // have a play, manipulate and display paragraph (p) in multiple ways
 
    cout << "-----------------------------------------------------\n"
            "Display: hcat(p, frame(p))                           \n"
            "-----------------------------------------------------\n";
            
    vectorOut(hcat(p,frame(p)));
 
    cout << "-----------------------------------------------------\n"
            "Display: hcat(frame(p), p)                           \n"
            "-----------------------------------------------------\n";
    vectorOut(hcat(frame(p),p));
 
    return 0;
}