## algorithm class cpp
> imp points about `#include<algorithm>`


### reverse(start_iterator, end_iterator)
```cpp    
vector<int> vec ={1 , 2, 3, 4, 5, 6, 7, 8, 9 };
reverse(vec.begin(), vec.end()); 
//note [start, end) end is not encluded
```   

### distance(a.begin(), iterator) 
```cpp
auto it = find(arr.begin(), arr.end(), value);
int index = distance(arr.begin(), it);
/*
it gives distance of that iterator from begining so, we can use this to find index of an element 
*/
```

### binary_search
```cpp
vector<int> vec ={1 , 2, 3, 4, 5, 7, 7, 8, 9, 13, 15};
int x = 12;
binary_search(first_iterator, last_iterator, x); //false
// Tests whether x exists in sorted vector or not

lower_bound(first_iterator, last_iterator, x); //iterator to 9
/*
points to first element <= x
– returns an iterator pointing to the first element in the
range [first,last) which has a value not less than ‘x’.
*/

upper_bound(first_iterator, last_iterator, x); //iterator to 13
/*
points to first element > x
– returns an iterator pointing to the first element in the
range [first,last) which has a value greater than ‘x’.

*/

```

## std::next_permutation 
```cpp

    /**
     * 
     * template 
     *  bool next_permutation (BidirectionalIterator first,
     *                      BidirectionalIterator last);
     *  Parameters: 
     *  first, last : Bidirectional iterators to the initial
     *  and final positions of the sequence. The range 
     *  used is [first, last), which contains all the elements 
     *  between first and last, including the element pointed 
     *  by first but not the element pointed by last.
     *
     *  return value: 
     *  true : if the function could rearrange 
     *  the object as a lexicographicaly greater permutation.
     *  Otherwise, the function returns false to indicate that 
     *  the arrangementis not greater than the previous, 
     *  but the lowest possible (sorted in ascending order).
     */

    string str = "ABC"

    std::next_permutation(str.begin(), str.end());
    cout << str; // str-> "ACB"

    std::prev_permutation(str.begin(), str.end());
    cout << str; // str-> "ABC"

    do {
        cout << str << " -> ";
    } while (std::next_permutation(str.begin(), str.end()));

    /**
     * output for above code 
     * ABC -> ACB -> BAC -> BCA -> CAB -> CBA -> 
    */

```