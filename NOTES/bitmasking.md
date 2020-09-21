## bitmask cpp

```cpp
    // bitwise AND => '&'
        0 , 1 -> 0
        0 , 0 -> 0
        1 , 1 -> 1
        1 , 0 -> 0

    // bitwise OR  => '|'
        0 , 1 -> 1
        0 , 0 -> 0
        1 , 1 -> 1
        1 , 0 -> 1

    // bitwise XOR => '^'  
        0 , 1 -> 1
        0 , 0 -> 0
        1 , 1 -> 0
        1 , 0 -> 1

    // compliment '~'
        0 -> 1
        1 -> 0
    
    1 << n ==> 2^n;

```
* shift operators,

    #### left shift  '<<'
    ```cpp
        a << 1  =>  a * 2
        a << b  =>  a * 2^b
    ```

    #### right shift  '>>'
    ```cpp
        a >> 1  =>  a / 2
        a >> b  =>  a / 2^b
    ```

### check num is odd/even
```cpp
    int num = 7 // 1 1 1 
    if (num & 1) {
        // num is odd
    } else {
        // num is even
    }
```

### count setbits 
```cpp
    int count_set_bits(int num) {
        int count = 0;
        while(num) {
            num = num & (num - 1);
            count++;
        }
        return count;
    }
```

### XOR swap very fast
```cpp
    int a = 5;
    int b = 7;
    a = a ^ b; // (5 ^ 7)         -> 
    b = a ^ b; // (5 ^ 7) ^ (7)   -> 5 
    a = a ^ b; // (5 ^ 7) ^ (5) -> 7 
```

### get, set, and unset i'th bit of a number
``` cpp
    //
    int get_i_bit(int num, int i) {
        int mask = 1 << i;
        return (num & mask) != 0 ? 1 : 0;
    }

    void set_i_bit(int &num, int i) {
        int mask = 1 << i;
        num = num | mask;
    }

    void unset_i_bit(int &num, int i) {
        int mask = ~(1 << i);
        num = num & mask;
    }
```