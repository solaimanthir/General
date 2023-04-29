//author: solai

#include <iostream>
#include <cstring>

using namespace std;

class baseClass {
public:
    virtual void display()
    {
        cout << "In Base class\n";
    }
};

class derClass : public baseClass {
public:
    void display()
    {
        cout << "In Derived class\n";
    }
};

int main() {
    baseClass * base = new derClass;
    
    derClass * der = dynamic_cast<derClass *>(base);
    
    if(der == nullptr)
    {
        cout << "can't typecast\n";
    }
    else
    {
        der->display();
        
        if(typeid(derClass) == typeid(*der))
            cout << "object type: derived\n";
    }
        
    delete base;
    
    return 0;
}
