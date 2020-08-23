## map class cpp map and multimap 
> imp points about `#include <map>`

* implemented using `binary search tree` hence provides insert, update and, delete in just O(log(n)) time


#### some genrale fun/methods in map
```cpp
    map <int, int> g;

    // insert element at random order
    g.insert(pari<int, int>(3, 4)); // first value is key and second is value 
    g.insert(make_pair(2, 5));
    g.insert(make_pair(1, 4));
    g.insert(make_pair(4, 5));
    g.insert(make_pair(7, 23));
    g.insert( {8, 2} );
    g.insert( {9, 1} );

    // printing the map 
    for (auto it = g.begin(); it != g.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    // assigning the elements from g to s 
    map<int, int> s(g.begin(), g.end());

    g.size(); // return number of element in map or size
    g.empty(); // checks whether map is empty or not
    g.begin();
    g.end();
    
    g.at(key);
      or 
    g[key];

    swap(g, m);
        or
    g.swap(m);
```

#### erasing some element from array
```cpp
    // Syntax for erasing a key
    map_name.erase(key);
    /*
    Parameters: The function accepts one mandatory parameter key which specifies the key to be erased in the map container.

    Return Value: The function returns 1 if the key element is found in the map else returns 0.
    */


    // Syntax for removing a position
    map_name.erase(iterator position);
    /*
    Parameters: The function accept one mandatory parameter position which specifies the iterator that is the reference to the position of the element to be erased.

    Return Value: The function does not returns anything.
    */ 


    // Syntax for erasing a given range
    map_name.erase(iterator position1, iterator position2)
    /*
    Parameters: The function accepts two mandatory parameters which are     described below:

        position1 – specifies the iterator that is the reference to the element from which removal is to be done.
        position2 – specifies the iterator that is the reference to the element upto which removal is to be done.

    Return Value: The function does not returns anything. It removes all the elements in the given range of iterators
    */ 
```

#### search in map
```cpp
    iterator map_name.find(key);
            or 
    constant iterator map_name.find(key);
            or 
    auto iterator = map_name.find(key);

```
#### lower_bound and upper_bound
```cpp
    map_name.lower_bound(key);
    /*
    Parameters: This function accepts a single mandatory parameter key which specifies the element whose lower_bound is to be returned.

    Return Value: The function returns an iterator pointing to the key in the map container which is equivalent to k passed in the parameter. In case k is not present in the map container, the function returns an iterator pointing to the immediate next element which is just greater than k. If the key passed in the parameter exceeds the maximum key in the container, then the iterator returned points to number of elements in the map as key and element=0.
    */

    map_name.upper_bound(key);
    /*
    Parameters: This function accepts a single mandatory parameter key which specifies the element whose upper_bound is returned.

    Return Value: The function returns an iterator pointing to the immediate next element which is just greater than k. If the key passed in the parameter exceeds the maximum key in the container, then returned iterator points to map_name.end(). Note that end() is a special iterator that does not store address of a valid member of a map.
    */    
```





## map class cpp unordered_map and unordered_multimap 
> imp points about `#include <unordered_map>`

* implemented using `hash table` hence provides insert, update and, delete in just O(1) time