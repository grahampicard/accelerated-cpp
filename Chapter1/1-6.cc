// What does hte following program do if, when it asks you for input, you 
// type two names (for example, Samuel Becket)?

// It'll first ask for my name, once I provide it, it'll greet me and ask me 
// what the second name is. Which I then provide

#include <iostream>
#include <string>

int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name
        << std::endl << "And what is yours? ";
    std::cin >> name;
    std::cout << "Hello, " << name
        << "; nice ot meet you too!" << std::endl;
    return 0;
}