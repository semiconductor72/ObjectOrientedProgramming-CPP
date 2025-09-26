#include <iostream>
#include <string>
int main()
{
    int a, b;
    std::string str;
    std::cout << "\nPlease enter your name \n";
    std::cin >> str;
    std::cout << "Name : " << str;
    std::cout << "\nPlease enter the numbers of which you want to do addition\n";
    std::cout << "\na = ";
    std::cin >> a;
    std::cout << "\nb = ";
    std::cin >> b;
    std::cout << "\nAddition = " << a + b;
}