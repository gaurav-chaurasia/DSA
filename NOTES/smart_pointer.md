## imp points about smart pointers

* they can only point to HEAP ALLOCATED memory 
* `#include <memory>`
    * `unique_ptr`
    * `shared_ptr`

```cpp
#include <memory>
//to use smart pointer you want to include hedder file 
```

### c++ smart pointers

#### unique_ptr
```cpp
    unique_ptr<int> ptr {new int {100}}; // syntax for declaring unique ptr
    *ptr; 
    //the value of above line is 100
    
    *unique pointers are unique so no two pointer can points to same memory on heap*

    ptr.get(); 
    //gives ptr object 0x563773
    
    ptr.reset();
    //now ptr points to null pointer

    unique_ptr< Player > player1 = new Player;
    //unique prt of type player 
    
    (*player1).set_player();
    player1 -> set_player();

    vector< unique_ptr< Account > > unique_ptr_vector;  
    /*
    above line shows how to declare vector of unique_ptr and unique_ptr of account object
    */

    unique_ptr< Account > ptr {new int {100}};
    
    unique_ptr can not be copied or assigned it only can be moved
    
    unique_ptr_vector.push_back( ptr );
    you can not simply push a pointer to vector that will give you compiler error 
    
    unique_ptr_vector.push_back( move.(ptr) );
    //you need to move the pointer


    unique_ptr<Account> ptr = make_unique<Account>(100);
                            or 
        auto ptr = make_unique<Account>(100);

```
#### shared_ptr
```cpp
class T {
    // some class with some properties
}
        shared_ptr< T > ptr = {new int {100}}; 

        ptr.use_count(); 
        //returns number of shared pointer pointing to the heap object

        auto ptr1 = make_shared< int >(100);
```