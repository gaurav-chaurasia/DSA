## maths formula and concpte
> to use diff math functions like log, sine...etc 
> include headder file `#include <math.h>`


### number of digit
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

### Arithematic and geometric progression
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

### Prime Numbers
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

### factorials
```cpp
Trailing 0s in N! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....

                  //similarly count of any number x in factorial can be found
                  = floor(n/x) + floor( n/(x*x) ) + floor(n/(x*x*x)) + ....

```
### permutations
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

### fraction 
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