## iterator class cpp
> imp points about `#include <iterator>`

```cpp
using namespace std;
vector <int> vec {1, 2, 3, 4, 5, 6};

vector <int>::iterator it = vec.begin()
auto it = vec.begin() 
/* 
it is an object and holds address of 1 in vector, 
auto automatically deduse the type of iterator 
*/
    it = vec.end() // points no where 
    it = vec.end() - 1; // points to 6 the last element of vector

//  1   2   3   4   5   6   end    //in case of vectors
//  []  []  []  []  []  []  []
 
    vector <int> ::const_iterator it = vec.begin();
                    //or 
            auto it = vec.cbegin(); // constant iterator means value "*it" can't be changed!

    vector <int> ::reverse_iterator it = vec.rbegin()
                    //or
            auto it = vec.rbegin(); //reverse iterators 
            auto it = vec.rend();
```