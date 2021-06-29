// Write a function named center(const vector<string>&) that returns a picture
// in which all the lines of the original picture are padded out to their full
// width, and the padding is as evenly divided as possible between the left
// and right sides of the picture. What are the properties of pictures for
// which such a function is useful? How can you tell whether a given picture
// has these properties?

// expected result
//  one
//  two
// three
// four

// pseudo
//  1.  iterate through each item of the string
//  2.  find the maximum string length
//  3.  iterate again through each item, and pad it by
//      the MAX - val / 2 on the left & right (if it's not even, then make the 
//      left side have one less)
//  4.  print the image
//  5.  return 0


#include <string>
#include <vector>

using std::string;
using std::vector;

string center(const vector<string>&) {

}

int main() {
  vector<string> a = {"one", "two", "three", "four"};
}



