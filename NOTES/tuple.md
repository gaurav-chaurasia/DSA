## tuple
> imp points about `#include <tuple>`   

```cpp

    // Declaring tuple 
    tuple <char, int, float> t1; 
    tuple <int, int, int> t2;

    // Declaring and Initializing 2 tuple 
    tuple <int, int, int> tup1(1, 2, 3); 
    tuple <char, char, char> tup2('G', 'K', 'C'); 

    // Assigning values to tuple using make_tuple() 
    t1 = make_tuple('a', 10, 15.5);  
    t2 = make_tuple(3, 8, 99);  


    // Printing initial tuple values using get() 
    cout << get<0>(t1) << endl; // a
    cout << get<1>(t1) << endl; // 10
    cout << get<2>(t1) << endl; // 15.5


    // Use of get() to change values of tuple 
    get<0>(geek) = 'b'; 
    get<2>(geek) =  20.5;


    // Swapping tup1 values with tup2 
    t1.swap(t2);  


    // Concatenating 2 tuples to return a new tuple 
    auto tup3 = tuple_cat(tup1,tup2);
    cout << get<0>(tup3) << endl; // 1
    cout << get<1>(tup3) << endl; // 2
    cout << get<2>(tup3) << endl; // 3
    cout << get<3>(tup3) << endl; // G
    cout << get<4>(tup3) << endl; // K
    cout << get<5>(tup3) << endl; // C

```