## iterator class cpp
> imp points about `#include <utility>`


```cpp
#include <utility>
//to use pair we must include utility headder file 

pair <char, int> pair1; 
//initialized to default values

pair <char, int> pair2('x', 5); 
// we can initialize it also while declaring 

pair <int, string> pair3 = make_pair(3, "gaurav_chaurasia");
pair1.swap(pair2);
```