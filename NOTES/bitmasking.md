## bitmask cpp
## bit manupulation and tricks  
> imp points about `bit operations`  

>  
>  [`properties`](#properties)  
>  [`general`](#sort)  
>  [`shift_operators`](#shift_operators)  
>  [`check_odd___even`](#odd___even)  
>  [`count_setbits`](#count_setbits)  
>  [`XOR_swap`](#XOR_swap)  
>  [`get__set__unset`](#get__set__unset)    
>  


### properties
```cpp
     1) property of XOR i.e for any number x, x^x =0.
```

### general
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
### shift_operators

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

### odd___even
- fast way to check the odd even
```cpp
    int num = 7 // 1 1 1 
    if (num & 1) {
        // num is odd
    } else {
        // num is even
    }
```

### count_setbits 
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

### XOR_swap
```cpp
    int a = 5;
    int b = 7;
    a = a ^ b; // (5 ^ 7)         -> 
    b = a ^ b; // (5 ^ 7) ^ (7)   -> 5 
    a = a ^ b; // (5 ^ 7) ^ (5) -> 7 
```

### get__set__unset
- get i'th bit of a number
- set i'th bit of a number
- unset i'th bit of a number
 
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