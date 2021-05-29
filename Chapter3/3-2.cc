//  Write a program to print quintiles
//
//  Pseudo:
//  1.  Ask for input
//  2.  Create a vector for inputs
//  3.  Read in all numbers
//  4.  Sort values
//  5.  Calcluate break points for quintiles
//  6.  Print value at breakpoints 

#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

int main()
{
    std::cout << "Enter a range of numbers, then EOF: ";

    // create a vector for inputs
    double x;
    std::vector<double> numbers;

    while (std::cin >> x) {
        numbers.push_back(x);
    }

    // Sort values
    sort(numbers.begin(), numbers.end());

    // Calculate break points for quintiles
    std::vector<double>::size_type size = numbers.size();

    if (size < 5) {
        std::cout << std::endl 
                  << "You need to enter 5 numbers"
                  << std:: endl;
        return 1;
    }

    // Quintile size
    int cutoff;
    cutoff = round(size / 5);

    std::cout << cutoff;

}