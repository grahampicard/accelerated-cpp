#include <iostream>
#include <string>

int main()
{
    // ask for a person's name
    std::cout << "Enter in shape size: ";

    // read the name
    int rows;
    std::cin >> rows;

    // Create a square
    for (int r = 0; r != rows; ++r) {
        std::cout << "*" ;
    }
    std::cout << std::endl;
    for (int r = 1; r != rows - 1; ++r) {
        std::cout << "*";
        for (int r = 1; r != rows - 1; ++r) {
            std::cout << " ";
        } 
        std::cout << "*";
        std::cout << std::endl;
    } 
    for (int r = 0; r != rows; ++r) {
        std::cout << "*" ;
    }
    std::cout << std::endl;
    return 0;

}
