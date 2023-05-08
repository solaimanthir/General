//Author: Solai

#include <iostream>
#include <cstring>

using namespace std;

class StrClass {
public:
    char * name;
    
    StrClass() {
        name = nullptr;
    }

    // deep copy
    StrClass(const StrClass& other) {
        name = new char[strlen(other.name) + 1];
        strncpy(name, other.name, strlen(other.name));
    }
    
    ~StrClass()
    {
        delete[] name;
    }
};

int main() {
    StrClass deep;
    deep.name = new char[5];
    strncpy(deep.name, "good", 5);
    
    StrClass deepcopy = deep;
    strncpy(deep.name, "okay", 5);
    cout << "orig is " << deep.name << endl;
    cout << "copy is " << deepcopy.name << endl;
    
    delete[] deep.name;
    deep.name = nullptr;
  
    cout << "copy is " << deepcopy.name << endl;
    
    //memory allocated for deepcopy.name will be freed in destructor
    return 0;
}
