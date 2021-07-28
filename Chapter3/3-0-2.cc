// (S3.2.2 / 46)
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << "Please enter your first name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name << "!" << std::endl;

  // ask for and read the miderm and final grades
  std::cout << "Please enter your midterm and final exam grades";
  double midterm, final;
  std::cin >> midterm >> final;

  // ask for the homework grades
  std::cout << "Enter all your homework grades, "
            << "followed by end-of-file: ";

  double x;
  std::vector<double> homework;

  // invariant:
  //  we have read count grades so far, and
  //  sum is the sum of the first count grades
  while (std::cin >> x) {
    homework.push_back(x);
  }

  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = homework.size();

  if (size == 0) {
    std::cout << std::endl
              << "You must enter your grades. "
                 "Please try again."
              << std::endl;
    return 1;
  }

  sort(homework.begin(), homework.end());

  // compute the median homework
  vec_sz mid = size / 2;
  double median;
  median =
      size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

  // compute and write the final grade
  std::streamsize prec = std::cout.precision();
  std::cout << "Your final grade is " << std::setprecision(3)
            << 0.2 * midterm + 0.4 * final + 0.4 * median
            << std::setprecision(prec) << std::endl;
  return 0;
}
