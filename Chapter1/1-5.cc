// Is this program vlaid? If not, say why not and rewrite it to be valid

// no because x is referenced outside of the execution block

// #include <iostream>
// #include <string>

// int main()
// {
//     {   std::string s = "a string";
//     {   std::string x = s + ", really";
//         std::cout << s << std::endl; }
//         std::cout << x << std::endl;
//     }
//     return 0;
// }

#include <iostream>
#include <string>

int main()
{
    {   std::string s = "a string";
    {   std::string x = s + ", really";
        std::cout << s << std::endl; 
        std::cout << x << std::endl;
    }}
    return 0;
}