/*
    They are dynamic arrays with the capability to adjust itself automatically whenever elements are inserted or deleted.
    Its elements are stored contiguously; So, elements can be accessed using iterators.
    Inserting elements at the front or in the middle takes linear time.
    Removing last element takes constant time because resizing of vector is not needed.
    Time-complexity associated with vectors are:
        To insert or remove data at the end - O(1), constant time.
        To insert or remove data at other positions - O(N), Linear time.
        Resizing of the vector - O(N), Linear time.
        Read the current size - O(1), constant time.
        Arbitrary access - O(1), constant time.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr;
    vector<int> arr1;
    vector<int> arr2;

    for(int i = 50; i <= 350; i = i + 50)
    {
        arr.push_back(i);
    }

    cout << "\narr's iteration using begin and end:\n";
    for(auto i = arr.begin(); i != arr.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << "\n############\n";

    cout << "\narr's iteration using rbegin and rend:\n";
    for(auto i = arr.rbegin(); i != arr.rend(); ++i)
    {
        cout << *i << " ";
    }
    cout << "\n############\n"; 

    cout << "capacity: " << arr.capacity() << ", max size: " << arr.max_size()
        << ", size: " << arr.size() << "\n";
    
    if(arr.empty())
    {
        cout << "vector is empty\n";
    }
    else
    {
        cout << "vector is not empty\n";
    }

    arr.resize(5);
    cout << "arr's size after resize(): " << arr.size() << "\n";

    cout << "arr's capacity before reserve(15) is " << arr.capacity() << "\n";
    arr.reserve(15);
    cout << "arr's capacity after reserve(15) is " << arr.capacity() << "\n";

    cout << "arr's elements: \n";
    for(auto i = arr.begin(); i != arr.end(); ++i)
    {
        cout << *i << " ";
    }

    arr.shrink_to_fit();
    cout << "\narr's capacity after shrink_to_fit() is " << arr.capacity() << "\n";

    cout << "arr's size is " << arr.size() << "\n";
    /*clears the vector*/
    arr.clear();
    cout << "arr's size after clear() is " << arr.size() << " now\n";

    /*makes arr2 to be of size 10 with each element 
    assigned with value 35*/
    arr2.assign(10, 35);

    /*inserts value 7 at index 3 in vector*/
    arr2.emplace(arr2.begin()+3, 7);

    /*inserts value 8 at the vector's end*/
    arr2.emplace_back(8);

    /*removes the last element in vector*/
    arr2.pop_back();

    /*inserts value 9 at the end*/
    arr2.push_back(9);

    /*removes the 2nd element*/
    arr2.erase(arr2.begin()+1);

    /*inserts value 75 as the 2nd element*/
    arr2.insert(arr2.begin()+1, 75);

    for(int i = 11; i < 15; ++i)
    {
        arr1.push_back(i);
    }

    cout << "before swap, arr1 is";
    for(auto it = arr1.begin(); it != arr1.end(); ++it)
    {
        cout << ' ' << *it;
    }
    cout << '\n';

    cout << "before swap, arr2 is";
    for(auto i = 0; i < arr2.size(); ++i)
    {
        cout << ' ' << arr2[i];
    }
    cout << '\n';

    arr1.swap(arr2);

    cout << "after swap, arr1 is";
    for(auto it = arr1.begin(); it != arr1.end(); ++it)
    {
        cout << ' ' << *it;
    }
    cout << '\n';

    cout << "after swap, arr2 is";
    for(auto i = 0; i < arr2.size(); ++i)
    {
        cout << ' ' << arr2[i];
    }
    cout << '\n';

    int* ptr = arr2.data();
    cout << "arr2's value at index 2 using at() is " << arr2.at(2) << '\n';
    cout << "arr2's value at front using front() is " << arr2.front() << '\n';
    cout << "arr2's value at last using back() is " << arr2.back() << '\n';
    cout << "arr2's first element using data() is " << *ptr << '\n';

    return 0;
}
