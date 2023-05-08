#include<bits/stdc++.h>
#include <iostream>
#include <stdexcept>

using namespace std;

int division(int a, int b)
{
    if(0 == b)
    {
        throw std::invalid_argument("div by 0");
    }

    return a/b;
}

int main()
{
    try{
        int res = division(123, 0);
        cout << "div result: " << res << endl;
    }
    catch(std::exception& e){
        cout << "encountered exception: " << e.what() << endl;
    }
    
    return 0;
}
