#include <iostream>
#include <string>


class Myclass {
private:
    int a;
    int b;

public:
    int c;
    int d;
    int addition(int p, int q)
    {
        return p + q;
    }
};



//Global variable, we will try to fetch its value in local
// by using scope resolution operator
int d = 72;

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
    std::cout << "\n\nReference Variables";
    int c = 100;
    int &c_ref = c;
    std::cout << "\nc : " << c << "\nc_ref = " << c_ref;
    
    
    /*Operators in C++ */

//On Non static members
//---------------------------------------------------------------------------------------------------
    /* 1) Scope resolution operator*/
    std::cout << "\n\n1)Scope resolution operator";
    int d = 73;
    std::cout << "\nLocal d = " << d <<"\nGlobal d by using :: = "<< ::d;
    {
        int d = 74;
        std::cout << "\nvariable inside block d = " << d;
        std::cout << "\nGlobal d by using :: = " << ::d;
    }

    /*2) Declaration of Pointer to non static Member ::*    */
    std::cout << "\n\n2)Declaration of pointer to member ::* ";
    int Myclass::* ptrtomember_c = &Myclass::c;
    int Myclass::* ptrtomember_d = &Myclass::d;
    int (Myclass:: * fnptr)(int, int) = &(Myclass::addition);

    /*3) Accessing above non static member with the help of pointer operator*/
         /*derefrancing Pointer to non static member obj.*ptrtomember_c*/
    std::cout << "\n\n3)Operating of pointer to non static member obj.*ptrtomember_c ";
    Myclass obj;
    obj.c = 54;
    std::cout << "\nAccessing member through pointer obj.*ptrtomember = " << obj.*ptrtomember_c;
    std::cout << "\nMember function access (obj.*fnptr)(7,5) = "<< (obj.*fnptr)(7,5);

    /*4) Accessing above non static member with the help of pointer operator*/
     /*derefrancing Pointer to non static member objptr->*ptrtomember_d*/
    std::cout << "\n\n4)Operating of pointer to non static member objptr->*ptrtomember_d ";
    Myclass *objptr = &obj;

    objptr->d = 77;
    std::cout << "\nAccessing member through pointer objptr->*ptrtomember_d = " << objptr->*ptrtomember_d;
    std::cout << "\nMember function access (objptr->*fnptr)(4,9) = " << (objptr->*fnptr)(4,9);
}