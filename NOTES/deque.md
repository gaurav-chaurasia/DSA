## deque class cpp
> imp points about `#include <deque>`

```cpp
    /**
    *   The insert() function can be used in three ways:
    *       Extends deque by inserting a new element val at a position.
    *       Extends deque by inserting n new element of value val in the deque.
    *       Extends deque by inserting new element in the range [first, last).
    */
    deque<int> dec;
        dec.insert (iterator position, const value_type& val)
                        or
        dec.insert (iterator position, size_type n, const value_type& val)
                        or
        dec.insert (iterator position, InputIterator first, InputIterator last)
    /**
    *  Parameters: The function accepts four parameters which are specified as below:
    *
    *       1) position – Specifies the position where the element/elements are to be inserted.
    *       2) val – specifies the value to be assigned to newly inserted element.
    *       3) n – specifies the number of elements to insert. Each element is initialized to a copy of val.
    *       4) first, last – specifies the iterators specifying a range of elements which is to be inserted. 
    *           The range  includes all the elements between first and last, including the element pointed by 
    *           first but not the one pointed by last.
    *
    *   Return value: The function returns an iterator that points to the first of the newly inserted elements.
    */

    deque<int> dq = { 1, 2, 3, 4, 5 }; 
    deque<int>::iterator it = dq.begin(); 
    ++it; // it-> 1

	it = dq.insert(it, 10); // 1 10 2 3 4 5
	//*it-> 10 

    dq.insert(it, 2, 0); // 1 0 0 2 3 4 5 

	vector<int> v(5, 10); 
    dq.insert(it, v.begin(), v.end()); // 1 10 10 10 10 10 2 3 4 5  
```

```cpp
	deque<int> deque1{ 1, 2, 3 }; 
    deque<int> deque2{ 3, 2, 1, 4 }; 
    deque1 = deque2; // deque1 -> {3, 2, 1, 4}
```

```cpp
	deque<int> dec = {1, 2, 3, 4, 5};
	
	dec.push_back(6);
	dec.push_front(0);

	dec.pop_back();
	dec.pop_front();

	int last = dec.last(); // returns last element
	int first = dec.first(); // returns first element 

	dec.erase(it);
	dec.push_front(1);

	dec.at(0); // 1

	deque1 = {1, 2, 3, 4}
	deque2 = {3, 5, 7, 9}
	deque1.swap(deque2); //
			or
	swap(deque1, deque2);
```