## bitset
> imp points about `#include <bitset>`

>
>  [`general`](#general)  
>  [` `]()  
>  [` `]()  
>  [` `]()  
>  


### general
- space taken by bitset bs is less than that of bool bs[N] and vector bs(N)
- We can access each bit of bitset individually with help of array indexing operator [] that is bs[3] shows bit at index 3
- bitset starts its indexing backward
- We can construct a bitset using integer number as well as binary string via constructors

```cpp
          bits
    bitset<32> bs;         // 00000000000000000000000000000000
    bitset<32> bs(20);     // 00000000000000000000000000010100
    bitset<32> bs("1100"); // 00000000000000000000000000001100


    bitset<8> bs;   // 00000000
    bs[1] = 1;      // 00000010 // setting first bit (or 6th index)
    bs[4] = bs[1];  // 00010010

    cout << bs << endl; // 00010010
```
```cpp
    bitset<8> bs;   // 00000000
    bs[1] = 1;      // 00000010 // setting first bit (or 6th index)
    bs[4] = bs[1];  // 00010010


    int ones  = bs.count();             // 2
    int zeros = bs.size() - bs.count(); // 6


    // test function return 1 if bit is set else returns 0
    for (int i = 0; i < bs.size(); i++)
        cout << bs.test(i) << " ";

    bs.any()  // any function returns true, if atleast 1 bit is set
    bs.none() // none function returns true, if none of the bit is set

    bs.set()      // bset.set() sets all bits
    bs.set(4, 0); // bset.set(pos, b) makes bset[pos] = b
    bs.set(4)     // bset.set(pos) makes bset[pos] = 1  i.e. default is 1

    
    bs.reset(2); // reset function makes all bits bs[2] = 0
    bs.reset();  // reset function makes all bits 0

    bs.flip();   // flip function flips all bits i.e. 1 <-> 0 and 0 <-> 1
    bs.flip(2);  // flip function flips bit at pos 2
```