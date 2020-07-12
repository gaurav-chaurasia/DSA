## iterator class cpp
> imp points about `#include <utility>`

#### genral 
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

#### push back pair in vector
```cpp
    vector<pair<int, int>> vec;
    vec.push_back(make_pair(38, 99));
    // to push pair in vector of pair
```

#### sort vector of pairs
```cpp
    vector<pair<int, int>> pair;
    pair.push_back(make_pair(1, 2));
    pair.push_back(make_pair(2, 1));
    pair.push_back(make_pair(1, 1));
    pair.push_back(make_pair(2, 2));
    pair.push_back(make_pair(3, 3));
    pair.push_back(make_pair(3, 1));
    sort(pair.begin(), pair.end());
    /*
        pair = {
            {1, 1},
            {1, 2},
            {2, 1},
            {2, 2},
            {3, 1},
            {3, 3}
        };
    */
```