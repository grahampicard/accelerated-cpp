// include directives and using-declarations for library facilities
// code for MEDIAN function
// code for grade(double, double, double)
// code for grade(double double, const vector<double>&

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <istream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::setprecision;
using std::streamsize;
using std::vector;

// Calculations
double median(vector<double> vec) {
  // first, we define a datastructure to handle size.
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0) throw domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
  if (hw.size() == 0) throw domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

// I/O
// in this case, we are reading directly from an input stream, and we are
// returning the input stream itself.
istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while (in >> x) hw.push_back(x);

    // clear stream for input to work
    in.clear();
  }
  return in;
}

int main() {
  cout << "Please enter your first name: ";
  std::string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // ask for and read the midterm and final grades
  cout << "Please enter your midterm and final grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // ask for the homework grades
  cout << "Enter all your homework grades, "
          "followed by end-of-file: ";

  vector<double> homework;

  // read the homework grades
  read_hw(cin, homework);

  try {
    double final_grade = grade(midterm, final, homework);
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) << final_grade
         << setprecision(prec) << endl;
  } catch (domain_error) {
    cout << endl
         << "You must enter your grades. "
            "Please try again."
         << endl;
    return 1;
  }
}
