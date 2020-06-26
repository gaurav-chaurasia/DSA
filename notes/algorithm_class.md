## algorithm class cpp
> imp points about #include<algorithm>


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
