/*Author: Solai*/

#include <iostream>
#include <cstring>

using namespace std;

class StrClass {
public:
    char * name;
    
    StrClass() {
        name = nullptr;
    }

    StrClass(const StrClass& other){
        name = other.name; //shallow copy
    }

    ~StrClass()
    {
        delete[] name;
    }
};

int main() {
  
    StrClass shallow;
    shallow.name = new char[5];
    strncpy(shallow.name, "good", 5);
    
    //shallowcopy.name point to memory pointed by shallow.name
    StrClass shallowcopy = shallow;
    cout << "copy is " << shallowcopy.name << endl;
    
    delete[] shallow.name;
    shallow.name = nullptr;
    shallowcopy.name = nullptr;
  
    return 0;
}
