#include <iostream>
#include <string>

int main()
{
    
    int number_1;
    int number_2;
    
    std::cout << "Enter a number: ";    
    std::cin >> number_1;
    std::cout << "Enter a number: ";    
    std::cin >> number_2;

    if (number_1 > number_2) {
        std::cout << "Number 1 is bigger";
    } else if (number_1 == number_2) {
        std::cout << "Equal";
    } else {
        std::cout << "Nubmer 2 is bigger" << std::endl;
    }
}