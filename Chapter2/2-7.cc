#include <iostream>
#include <string>

int main()
{
    const int invariant = -6;
    int r = 10;

    while(r > invariant) {
        std::cout << r;
        --r;
    }
    
}