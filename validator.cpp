/*Author: Solai*/

#include <iostream>

using namespace std;

void validateNum(const string& str)
{
    int len = str.length();
    int i = 0;
    int num = 0;
    int sum_of_digits = 0;
    bool isEvenPos = false;

    /*can include length checks here based on use case.
    For example: length has to be >= 13 and <= 16 for 
    credit card numbers*/

    while(i < len) 
    {
        if((str[i] < '0') || (str[i] > '9'))
        {
			cout << "#########################################" << endl;
            cout << "Incorrect input" << endl;
			cout << "#########################################" << endl;
			cout << endl;
            return;
        }

        ++i;
    }
    
    i = len - 1;
    for(; i >= 0; --i)
    {
        num = str[i] - '0';

        if(true == isEvenPos)
            num *= 2;

        sum_of_digits += (num/10);
        sum_of_digits += (num%10);

        isEvenPos = !isEvenPos;
    }

    cout << "#########################################" << endl;
    if(0 == (sum_of_digits%10))
        cout << str << " is a valid number" << endl;
    else
        cout << str << " is an invalid number" << endl;
    cout << "#########################################" << endl;
    cout << endl;
}

/*This program is an illustration for Luhn Algorithm*/
int main()
{
    string num_str;

    while(true)
    {
        cout << "Enter q to quit or" << endl;
        cout << "Enter a number to check" << endl;
        cin >> num_str;

        if("q" == num_str)
            break;

        validateNum(num_str);
    }

    return 0;
}