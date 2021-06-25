## maths formula and concpte
> to use diff math functions like log, sine...etc 
> include headder file `#include <math.h>`



>  
>  [`LCM_and_GCD`](#LCM_and_GCD)  
>  [`number_of_digit`](#number_of_digit)  
>  [`Arithematic and geometric progression`](#AP_and_GP)  
>  [`Prime_Numbers`](#Prime_Numbers)  
>  [`factorials`](#factorials)  
>  [`permutations`](#permutations)  
>  [`fraction`](#fraction)  
>  [`decimal_to_binary`](#decimal_to_binary)  
>  [`binary_to_decimaly`](#binary_to_decimal)  
>  


### `LCM_and_GCD`
- LCM (Least Common Multiple) of two numbers is the smallest number which can be divided by both numbers
- A simple solution is to find all prime factors of both numbers, then find union of all factors present in both numbers. Finally, return the product of elements in union
- below is the implimentation for finding all the prime factors of number  
```cpp
    // 24 = (2^3)*(3) ==> [2, 2, 2, 3]
    vector<int> prime_factors(int n) {
        vector<int> f;

        for (int x = 2; x*x <= n; x++) {
            while (n%x == 0) {
                f.push_back(x);
                n /= x;
            }
        }

        if (n > 1) 
            f.push_back(n);

        return f;
    }
```
- An efficient solution is based on the below formula for LCM of two numbers ‘a’ and ‘b’
```cpp
	a x b = LCM(a, b) * GCD (a, b)

	LCM(a, b) = (a x b) / GCD(a, b)
```
```cpp
	long long GCD(long long int a, long long int b) {
		if (b == 0)
			return a;
		return GCD(b, a % b);
	}

	long long LCM(int a, int b) {
		return (a / GCD(a, b)) * b;
	}
  
```
- [Detailed explanation for GCD](../ALGORITHM/docs/euclidean_algorithms.md)



### `number_of_digit`
```cpp
/*
number of digit can easily be find by deviding the number by 10 and 
increamenting the count by one each time till it reaches 0

timecomplexity will be O(number of digit)
better solution can be

number of digit of any number N is K;
    then 
*/
    K = floor(log(N) + 1);  

    log is base 10;

//timecomplexity will be O(1)
```

### `AP_and_GP`
```cpp
// nth term of an AP = a + (n-1) * d

where d = common difference;
      a = first term;

// Arithematic Mean = SUM OF ALL TERM IN AP / NUMBER OF TERMS IN THE AP;

// sum of 'n' terms of an AP = 0.5n(first term + last term);
                             = 0.5n[ 2a + (n-1)d ];

// If ‘a’ is the first term and ‘r’ is the common ratio:
    nth term of a GP = a*rn-1.
    
    Geometric Mean = nth root of product of n terms in the GP.
    
    Sum of ‘n’ terms of a GP (r < 1) = [a (1 – r*n)] / [1 – r].
    
    Sum of ‘n’ terms of a GP (r > 1) = [a (r*n – 1)] / [r – 1].
    
    Sum of infinite terms of a GP (r < 1) = (a) / (1 – r).

```

### `Prime_Numbers`
```cpp
/*
Naive Method to Check if a number is Prime:
  Algorithm:
    If, N is less than 2. It is not prime, return False.
    Else:
      Iterate from 2 to N-1 and check if any of the numbers between 2 and N-1 (both inclusive) divides N or not. If yes, then N is not prime, return False.
      Otherwise, return True.

timecomplexity is O(N)
we can do better by iterating till UnderRoot(N)
*/
```
```cpp
                *Sieve of Eratosthenes*
  
/*
  Using Sieve of Eratosthenes is the most efficient way of generating prime numbers upto a given number N.

  Following is the algorithm to find all the prime numbers less than or equal to a given integer n by Eratosthenes' method:

  Create a list of consecutive integers from 2 to n: (2, 3, 4, ..., n).
  Initially, let p equal 2, the first prime number.
  
  Starting from p2, count up in increments of p and mark each of these numbers greater than or equal to p2 itself in the list. These numbers will be p(p+1), p(p+2), p(p+3), etc..
  
  Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this number (which is the next prime), and repeat from step 3.
*/
	vector<bool> prime(n+1, true);
	prime.at(0) = false;
	prime.at(1) = false;
	for (int i = 2; i <= sqrt(n); i++) {
		for (int j = 2; j*i <= n; j++) {
			prime.at(i*j) = false;
		}
	}

// now we have prime vector whiche stores given number is prime or not in O(1) time

```



### `factorials`
```cpp
Trailing 0s in N! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....

                  //similarly count of any number x in factorial can be found
                  = floor(n/x) + floor( n/(x*x) ) + floor(n/(x*x*x)) + ....

```
### `permutations`
```cpp
    n C r = (n!) / (r! *(n-r)!);

    n P r = n! / (n-r)!


    n P n = n*(n-1)*(n-2)*......*1 = n!.
    n P 0 = n! / n! = 1.
    n P 1 = n.
    n P n-1 = n!.
    n P r/n P r-1 = n - r + 1.

// Permutation with repetition allowed: 
    The number of permutation or arrangements of N numbers with repetition allowed will be NN.
    For Example, permutaions of {1,2} with repetitions will be {{1,1}, {1,2}, {2,1},{2,2}}.

// Permutation with duplicates: 
    The number of permutations or arrangements of 
    N objects of which p1 are of one kind, 
    p2 are of second kind, ..., 
    pk are of k-th kind and the rest if any, 
    are of different kinds is: N! / (p1! * p2! *....*pk!).
```

### `fraction` 
```cpp
	50 / 22 => (44 + 6) / 22 => (2) + (6 / 22);

	// means if we want to calculate fraction till maybe 200 digit 
	/*
		we store leading value by floor(50/22) => 2
	*/ 
		str = '';
		str += to_string(floore(50/22));
		str.push_bacK('.'); // str => "2."
	/*
		Now we are left with  remainder(6) / denominator(22).

		Multiply the remainder by 10.
		Append remainder / denominator to str.
		remainder = remainder % denominator.

		and keep doing this till remainder = 0 or number of digit required
	*/
```

### `decimal_to_binary`
```cpp 
    void decimal_to_binary(int n, vector<int> &arr) {
        arr.clear();
        arr.resize(32);

        int i = 0;
        while (n > 0) {
            arr[i] = n % 2;
            n /= 2;
            i++;
        }

        reverse(arr.begin(), arr.end());
    }

    void decimal_to_binary(int n, string &str) {
        str = bitset<32>(n).to_string();

        cout << "[ " << str << " ]" << endl;
    }
```

### `binary_to_decimal`
```cpp
    int binary_to_decimal (int n /*binary num 0011010*/) {
        int num = n;
        int dec_value = 0;
        int base = 1;

        while (num) {
            int last_digit = num % 10;
            num /= 10;

            dec_value += last_digit * base;
            base = base * 2;
        }

        return dec_value;
    }

    int binary_to_decimal (string n /*decimal num "001011001"*/) {
        string num = n;
        int dec_value = 0;
        int base = 1;

        for (int i = num.size() - 1; i >= 0; i--) {
            if (num[i] == '1')
                dec_value += base;
            
            base = base * 2;
        }

        return dec_value;
    }

    int binary_to_decimal (string n) {
        return stoi(n, 0, 2);
    }
```