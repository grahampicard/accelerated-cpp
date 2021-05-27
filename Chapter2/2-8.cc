#include <iostream>
#include <string>

int main()
{
    // generate product of numbers in the range 1-10
    int product = 1;
    for (int j=1; j<=10;j++)
    {
        product = product * j;
    }
    
    // output results
    std::cout << product;
    std::cout << std::endl;
}