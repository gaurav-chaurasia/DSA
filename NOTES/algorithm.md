## algorithm class cpp
> imp points about `#include<algorithm>`


> `sort` [🎯](#sort)  
> `reverse` [🎯](#reverse)  
> `distance` [🎯](#distance)  
> `erase` [🎯](#erase(iterator))  
> `binary_search` [🎯](#binary_search)  
> `next_permutation` [🎯](#next_permutation)    
> ✔🔃🔰🚥🧷⚡🎯🧲📎



### sort
```cpp    
    vector<int> vec ={1 , 2, 3, 4, 5, 6, 7, 8, 9 };
    sort(vec.begin(), vec.end()); 
    // accending order

    sort(vec.begin(), vec.end(), greater<int>()); 
    // desending order
``` 

### reverse
```cpp    
    vector<int> vec ={1 , 2, 3, 4, 5, 6, 7, 8, 9 };
    reverse(vec.begin(), vec.end()); 
    //note [start, end) end is not encluded
```   

### distance
```cpp
    auto it = find(arr.begin(), arr.end(), value);
    int index = distance(arr.begin(), it);
    /*
    it gives distance of that iterator from begining so, we can use this to find index of an element 
    */
```

### erase
```cpp
    iterator list_name.erase(iterator position)
            or
    iterator list_name.erase(iterator first, iterator last)
    /**
     * 
     * position: 
     This parameter is used when the function is used to delete a single element. This parameter refers to an iterator which points to the element which is need to be erased from the list container.
     
     * first, last: 
     These two parameters are used when the list is used to erase elements from a range. The parameter first refers to the iterator pointing to the first element in the range and the parameter last refers to the iterator pointing to the last element in the range which is needed to be erased. This erases all the elements in the range including the element pointed by the iterator first but excluding the element pointed by the iterator last.
    */
    @example
                          a        b        pos
    vector<int> vec ={1 , 2, 3, 4, 5, 6, 7, 8, 9 };

    auto it = container.erase(pos);
              a        b        it
    vec ={1 , 2, 3, 4, 5, 6, 7, 9 };

    auto it = container.erase(a , b);
              it 
    vec ={1 , 5, 6, 7, 9 };


```

### binary_search
```cpp
    vector<int> vec ={1 , 2, 3, 4, 5, 7, 7, 8, 9, 13, 15};
    int x = 12;
                  ___________range_____________
    std::binary_search(first_iterator, last_iterator, x); //false
    // Tests whether x exists in sorted vector or not

    std::lower_bound(first_iterator, last_iterator, 12); //iterator to 13
    std::lower_bound(first_iterator, last_iterator, 9); //iterator to 9
    
    /*
    points to first element >= x
    – returns an iterator pointing to the first element in the
    range [first,last) which has a value not less than ‘x’.
    */

    std::upper_bound(first_iterator, last_iterator, 12); //iterator to 13
    /*
    points to first element > x
    – returns an iterator pointing to the first element in the
    range [first,last) which has a value greater than ‘x’.
    */

    //my
    std::first_equal_to_or_greater_than() // lower_bound >= x
    std::first_greater_than() // upper_bound > x
    std::first_equal_to_or_less_than() // custom <= x 
    std::first_less_than() // custom < x
    //

    template<typename ForwardIterator, typename T>
    ForwardIterator first_equal_to_or_less_than(ForwardIterator first, ForwardIterator last, T value) {
        
        auto it = std::lower_bound(first, last, value);
        
        if (*it == value) return it;

        return (it == first ? last : --it);
    
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator first_less_than(ForwardIterator first, ForwardIterator last, T value) {
        
        auto it = std::lower_bound(first, last, value);
        return (it == first ? last : --it);
    
    }

```

## next_permutation 
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