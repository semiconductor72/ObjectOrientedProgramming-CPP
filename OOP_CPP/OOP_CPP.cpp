#include <iostream>
#include <string>


class Myclass {
private:
    int a;
    int b;

public:
    int c;
    int d;

    static int e;
    static int f;

    int addition(int p, int q)
    {
        return p + q;
    }
};

/*Every static data member needs to define once globally otherwise comipiler will throw error*/
int Myclass::e = 90;
int Myclass::f = 91;


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

//-------------------------------------------------------------------------------------------------------------
/*static members*/
    std::cout << "\n\n\n\nStatic Members";
    Myclass teststatic;

    //we use general pointers to point static variables & functions both
    int* localptr1 = &Myclass::e;
    int* localptr2 = &Myclass::f;

    teststatic.e = 1;
    teststatic.f = 2;

    std::cout << "\nBefore init static e = "<< Myclass::e <<" f = "<< Myclass::f;
    std::cout << "\nBefore init static e = " << *localptr1 << " f = " << *localptr2;

    Myclass::e = 11;
    Myclass::f = 12;
    std::cout << "\nAfter init static e = " << teststatic.e << " f = " << teststatic.f;
    std::cout << "\nAfter init static e = " << *localptr1 << " f = " << *localptr2;

    //-----------------------------------------------------------------------------------
    //Dynamic Memory Allocation
    std::cout << "\n\n\nDynamic Memory Allocation";
    std::cout << "\nDynamic Memory Allocation by using new of single element";
   int *DynamicAllocation= new int(32);//you can assign value at the time of memory allocation
   *DynamicAllocation = 45;
   std::cout << "\nDynamic allocation value of single element = " << *DynamicAllocation;
   delete DynamicAllocation;

   //Dynamic memory allocation for array
   std::cout << "\n\n\nDynamic Memory Allocation by using new of array";
   int* arr = new int[5] {3,4,5,6,7};
   arr[0] = 30;
   arr[1] = 31;
   arr[2] = 32;
   arr[3] = 33;
   arr[4] = 34;
   std::cout << "\nArray values" << "\narr[0]" << arr[0] << "\narr[1]" << arr[1] << "\narr[2]" << arr[2] << "\narr[3]" << arr[3] << "\narr[4]" << arr[4];
   delete[] arr;

   //Dynamic memory allocation for object
   Myclass* ptrtoMyclass1 = new Myclass;
   ptrtoMyclass1 = &teststatic;
}
