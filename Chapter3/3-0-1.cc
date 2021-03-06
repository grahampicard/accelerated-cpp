// (S3.1 / 35)
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

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
  int count = 0;
  double sum = 0;

  // a variable into which to read
  double x;

  // invariant:
  //  we have read count grades so far, and
  //  sum is the sum of the first count grades
  while (std::cin >> x) {
    ++count;
    sum += x;
  }

  // write the result
  std::streamsize prec = std::cout.precision();
  std::cout << "Your final grade is " << std::setprecision(3)
            << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
            << std::setprecision(prec) << std::endl;
  return 0;
}
