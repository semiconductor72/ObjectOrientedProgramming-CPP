#include <iostream>
#include <string>

//this pointer class

class thisptr {

private:
    static int counter;
public:
    thisptr& display(void)
    {
        counter++;
        std::cout << "\nthis pointer example : "<< counter;
        return *this;//by derefrancing this pointer we are returning current object
    }

    void show(void)
    {
        std::cout << "\ninside show";
    }
};

int thisptr::counter = 0;


//what is abstract class?
//   --class has atleast 1 pure virtual function like virtual void speak() = 0; //Pure virtual function
//   --you cant/should not define object for abstract class

class Animal{
public:
    virtual void speak() = 0;//pure virtual function
};

class Dog :public Animal {
public:
    void speak() override
    {
        std::cout << "\nThis animal is Dog and it barks";
    }
};

class Cat :public Animal {
public:
    void speak() override
    {
        std::cout << "\nThis animal is Cat and it Meuw";
    }
};


//By default if access specifier is not used then its type is for class = private for struct = public

class fn_ovrldng {
public:
    void printvalue(int a)
    {
        std::cout << "\nprovided value is int : "<<a;
    }
    void printvalue(float a)
    {
        std::cout << "\nprovided value is float :" << a;
    }
    void printvalue(std::string s)
    {
        std::cout << "\nprovided value is string : " << s;
    }

};


//function overloading can be done outsie the class
void printvalue(int value)
{
    std::cout << "\nProvided value is integer: " << value;
}

void printvalue(float value)
{
    std::cout << "\nProvided value is floating: " << value;
}

void printvalue(std::string value)
{
    std::cout << "\nProvided value is string: " << value;
}

//operator overloading has to be inside the class
class op_overloading {
private:
    int p = 48;
public:

    op_overloading(int def=0)
    {
        p = def;
    }

    //ReturnType operator<symboll>(arguments){context}
    int operator*(int i)
    {
        std::cout << "\n\nOperator overloading performed";
        return p*i;
    }

    op_overloading operator+(op_overloading& argum)
    {
        op_overloading dummy;
        dummy.p = p + argum.p;
        return dummy;
    }

    int getvalueofP(void)
    {
        return p;
    }

};

class base1 {
public:
    int a;
    int b;
    base1()
    {
        a = 7;
        b = 8;
    }
};

class base2 {
public:
    int c;
    int d;
    base2()
    {
        c = 9;
        d = 10;
    }
};

/*Single inheritance : Single class is inheritated into single derived / child class
class A
class B:public A
{
}
*/
class SingleInheritance:public base1{
public:
    int get_valueofA(void)
    {
        return a;
    }
};

/*Multiple inheritance : Multiple classes are inheritated into single derived / child class
class A
class B
class C:public A,public B
{

}
*/
class MultipleInheritance :public base1, public base2 {
public:
    int get_valueofAplusD(void)
    {
        return a+d;
    }
};

/*Multilevel inheritance : The already Inherited class gets inherite to another derived class
class A
class B:public A
{

}

class C:public B
{

}
A into B into C
*/
class Multilevel1 :public base1 {
public:
    int h = 13;
    int get_valueofA(void)
    {
        return a;
    }
};

class Multilevel2 :public Multilevel1 {
public:
    int get_valueofAplusH(void)
    {
        return a+h;
    }
};

//Hierarcial inheritance : Multiple class get derived from single base class 
//Here dervd1 and drvd2 are derived from base1 class
class dervd1 :public base1 {

};

class dervd2 :public base1 {

};

//hybrid inheritance// the following example alsi illustraight the diamond problem
class a :public base1 {

};
class b :public base1 {

};

class c :public a, public b {

};


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

   //Placement new
   //char buffer[sizeof(Myclass)];
   //Myclass* obj = new (buffer) Myclass();  // Placement new places constructor at memory region you choose e.g stack, globally etc

   //Smart Pointers
   std::cout << "\n\n\nstarting of Smart pointers";
   std::cout << "\nUnique pointers to single element";
   std::unique_ptr<int> unqptr = std::make_unique<int>(5);
   *unqptr = 78;
   std::cout << "\nUnique Pointer value = " <<*unqptr;

   //only 1 uniqueue pointer can own the resource if you have to 
   //assign another pointer to same memory location then transfer the ownership
   std::unique_ptr<int>movedptr = std::move(unqptr);
   std::cout << "\nMoved owenership of Unique Pointer = " << *movedptr;

   std::cout << "\nUnique pointers to array";
   std::unique_ptr<int[]> uniqueptrarr = std::make_unique<int[]>(5);
   uniqueptrarr[0] = 60;
   int* rawptr1 = uniqueptrarr.get();
   *(rawptr1 + 1) = 61;
   uniqueptrarr[2] = 62;
   uniqueptrarr[3] = 63;
   uniqueptrarr[4] = 64;
   std::cout << "\nUnique pointer array" << "\nuniqueptrarr[0] = " << uniqueptrarr[0] << "\nuniqueptrarr[1] = " << uniqueptrarr[1];

   std::cout << "\n\nShared Pointer";
   std::shared_ptr<int> sharedptr1 = std::make_shared<int>(1);
   *sharedptr1 = 88;
   std::shared_ptr<int> sharedptr2 = sharedptr1;
   std::cout << "\nShared ptr values with" << "\nsharedptr1 = " << *sharedptr1 << "\nsharedptr2 = "<<*sharedptr2 <<"\nreference count = "<< sharedptr1.use_count();

   //how to print char number value?
   char ch = 70;
   std::cout << "\n\n\nchar ch = " << ch << " raw num = " << int(ch);

   //Inheritance
   std::cout << "\n\n\nLets start the inheritance\nMejorly there are 4 types of inheritance";
   std::cout << "\n1)Single Inheritance";
   std::cout << "\n2)Multiple Inheritance";
   std::cout << "\n3)Multilevel Inheritance";
   std::cout << "\n4)Hierarchical Inheritance";
   std::cout << "\n5)Hybrid Inheritance";

   //Single Inheritance  Base class to Derived Class
   std::cout << "\n\nSingle Inheritance";
   SingleInheritance drvd;
   std::cout << "\n a = "<< drvd.get_valueofA();

   //Multiple Inheritance
   std::cout << "\nMultiple Inheritance";


   //Pollymorphism
   std::cout << "\n\n\nPollymorphism";
   // -- Compile time pollymorphism/static pollymorphism/static binding -- it is achived by operator overloading or function overloading
   // 
   //Operator Overloading
   //operator overloading has to be inside class/object
   std::cout << "\n static Pollymorphism by Operator overloading";
   op_overloading ov1(5), ov2(8);
   int temp1 = ov1 * 7;
   
   std::cout << "\n overloaded value = "<< temp1;

   //static pollymorphism by operator overloading
   op_overloading add_result = ov1+ov2;
   std::cout << "\nValue of P = " << add_result.getvalueofP();


   //Function overloading
   //Function overloading need not to be inside the class/object

   printvalue(7);
   printvalue(3.14f);
   printvalue("\nSom");

   //static pollymorphism by function overloading
   std::cout << "\n static Pollymorphism by function overloading";
   fn_ovrldng fn;
   fn.printvalue(15);
   fn.printvalue(2.8f);
   fn.printvalue("\nEmbedded Systems");

   //Dyanamic pollymorphism
   //Dynamic pollymorphism by pure virtual function and function overriding
   //--Inheritance is issensial for dynamic pollymorphism
      //function overriding is different than function overloading
   //function overriding is used in dynamic pollymorphism/runtime pollymorphism.

   Animal* Abstractptr;
   Dog dd;
   Abstractptr = &dd;
   Abstractptr->speak();

   Cat cc;
   Abstractptr = &cc;
   Abstractptr->speak();

   //this pointer
   thisptr TP;
   TP.display().display().display().show();

   std::cout << "\n\n\n\n\n";
}
