## euclidean_algorithms


### Basic Euclidean Algorithm for GCD 
- The algorithm is based on the below facts `Time Complexity: O(Log min(a, b))` 
  - If we subtract a smaller number from a larger (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
  - Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find remainder 0.
```py
    # euclidean_algorithms for GCD
    int GCD(int a, int b) {
        if (a == 0)
            return b;
        
        return gcd(b % a, a);
    }
```

### Extended Euclidean Algorithm
- Extended Euclidean algorithm also finds integer coefficients x and y such that

```py
    ax + by = gcd(a, b) 
```

- The extended Euclidean algorithm updates results of gcd(a, b) using the results calculated by recursive call gcd(b%a, a). 
- Let values of x and y calculated by the recursive call be x1 and y1. 
- x and y are updated using the below expressions

```py
    x = y1 - ⌊b/a⌋ * x1
    y = x1
```

```cpp
    int Extended_GCD(int a, int b, int *x, int *y) {
        // Base Case
        if (a == 0) {
            *x = 0;
            *y = 1;
            return b;
        }
    
        int x1, y1; // To store results of recursive call
        int gcd = Extended_GCD(b%a, a, &x1, &y1);
    
        // Update x and y using results of
        // recursive call
        *x = y1 - (b/a) * x1;
        *y = x1;
    
        return gcd;
    }
```