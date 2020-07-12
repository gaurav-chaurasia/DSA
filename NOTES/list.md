## list class cpp
> imp points about `#include <list>`

* normally list refers to doubly linked list
* for singlly linked list we use for 

#### genral 
```cpp
    #include <list>
    //to use list we must include list headder file 

    list<int> int_list;
    list<char> char_list;
    list<float> float_list;
    list<double> double_list;
    list<long long> long_long_list;
    list<string> string_list;

    int_list.push_back(99);
    int_list.push_front(38);

    int_list.pop_back();
    int_list.pop_front(); 
    // simply pops an element from back and front respectivelly and do not return anything

    int_list.front(); // returns first element from list
    int_list.back(); // returns last element from list

    int_list.reverse(); // reverse the list container
    int_list.sort(); // sorts the list in acending order

    int_list.empty(); // returns true or false 
    int_list.size(); // reurns the size of list

```
#### intert element at any place
```cpp
    list <int> g;
    g.insert(pos_iter, ele_num, ele);
    // If ele_num is not mentioned, number of elements is default set to 1.
   /* 
    pos_iter: Position in the container where the new elements are inserted.
    ele_num: Number of elements to insert. Each element is initialized to a copy of val.
    ele: Value to be copied (or moved) to the inserted elements.
    
                                *Return Value* 
    This function returns an iterator that points to the first of the newly inserted elements. 
    */ 
```

#### erase an element or range of element
```cpp
    list <int> :: iterator it;
              or
            auto it;
    
    g.erase(it);

    g.erase(g.begin(), g.end());

```

#### travers in list
```cpp
    list<int> :: iterator it = int_list.begin();
                        or
            auto it = int_list.begin();

    for ( ; it != int_list.end(); it++) {
        cout << *it << " ";
    } cout << endl;


    // traverse in reverse 
    for (auto it = rbegin(); it != int_list.rend(); it++) {
        cout << *it << " ";
    } cout << endl;

```