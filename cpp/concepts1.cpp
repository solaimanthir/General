/*Author: Solai*/

/*
concepts covered:
Abstraction - involves hiding the implementation details of a class and exposing only the relevant information and functionality to the outside world.
In C++, abstraction is achieved through the use of abstract classes and interfaces.

Encapsulation is a fundamental principle of object-oriented programming that involves hiding the internal details of a class 
from the outside world, and only exposing a public interface for interacting with the class.
In C++, encapsulation is achieved through the use of access modifiers, such as public, private, and protected.

Polymorphism is achieved through two mechanisms in C++: 
function overloading and virtual functions.

Function overloading - a single function name can be used to define multiple functions 
with different parameter lists.

A virtual function is a member function of a class that can be overridden in a derived class.
A pure virtual function is a function that has no implementation in the base class and must be overridden by any derived class.

A friend class is a class that is granted access to the private and protected members of another class.

*/

#include <iostream>
using namespace std;

class food {
    friend class order;

private:
    int count;

public:
    void addItem() {
        cout << "adding cheese to the food" << endl;
    }

    virtual void prepare() {    //virtual function
        cout << "preparing food" << endl;
    }

    virtual void ingredients() = 0; // pure virtual function
};

class pizza : public food {
private:
    string type;

public:
    void prepare() {
        cout << "preparing pizza" << endl;
    }

    void ingredients()
    {
        cout << "adding ingredients to pizza" << endl; 
    }

    void setPizzaType(string pizzatype) {
        type = pizzatype;
    }

    string getPizzaType() {
        return type;
    }
};

class burger : public food {
public:
    void prepare() {
        cout << "preparing burger" << endl;
    }

    void ingredients()
    {
        cout << "adding ingredients to burger" << endl; 
    }
};

class order {
public:
    void setCount(food& fr){
        fr.count = 10;
    }
};

int main()
{
    food *fp;
    pizza p;
    burger b;

    fp = &p;
    fp->prepare(); //prints 'preparing pizza'
    p.setPizzaType("Hawaiian");
    cout << "pizza type is " << p.getPizzaType() << endl;
    cout << "##################" << endl << endl;

    fp = &b;
    fp->prepare(); //prints 'preparing burger'
    fp->addItem(); //inheritance
    fp->ingredients();

    return 0;
}
