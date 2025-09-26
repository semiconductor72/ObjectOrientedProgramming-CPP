#include <iostream>
#include <string>
int main()
{
    /*Input & Output*/
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

    /*Reference Variable*/
    int c = 100;
    int &c_ref = c;
    std::cout << "\n\nReference Variables\nc : " << c << "\nc_ref = " << c_ref;
}