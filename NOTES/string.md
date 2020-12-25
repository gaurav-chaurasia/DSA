## string in cpp
> imp points about `#include <string>`

```cpp
	#include <string>
	// to use smart pointer you want to include hedder file 
```

```cpp
	string str;
	getline(cin, str);
	// getline() to store a stream of characters   

	str.push_back('g'); 
	// pushes 'g' at the back of string

	str.pop_back();     
	// pops 'g' from the back of string

	str.capacity()  
	// returns the capacity allocated to the string, equal to or more than the size 


	auto it = str.end() // iterator to end of the string
	auto it = str.rend() // revers iterator to end of the string
	auto it = str.begin() // iterator to beginning of the string
	auto it = str.rbegin() // revers iterator to beginning of the string

	int postion = str.find('g') 
	int postion = str.find('gaurav') // returns first occurrence of gaurav 

	begin()=1  2 3 4 5 6 7 8  '\0'=end()
	-       - - - - - - -  

	char ch = str.front();
	char ch = str.back();

	str.empty() 
	// returs true or false

	str.append(" added word"); 
	// str = str + " added word"

	str.append(str1, start_index, end_index);   
	// appends part of other string  

	str.compare(str1) 
	// returns 0 is strings are same

```

### converting sring to int || string to double || string to float
* using `stoi` and `atoi` for string to int

#### stoi takes string input
```cpp
    int myint1 = stoi("45"); // 45
    int myint2 = stoi("3.14159"); // 3
    int myint3 = stoi("31337 geek"); //31337
   
	# stoi() can take upto three parameters, the second parameter
	is for starting index and third parameter is for base of
	input number.
	int stoi (const string&  str, size_t* index = 0, int base = 10); 

```

#### atoi take char array 
```cpp
    const char *str1 = "42"; 
    const char *str2 = "3.14159"; 
    const char *str3 = "31337 geek"; 
     
    int num1 = atoi(str1); //42
    int num2 = atoi(str2); //3
    int num3 = atoi(str3); //31337
    int atoi (const char * str); 
```

#### stod takes string input and converts it into double
```cpp
	string b = "5.4"; 
	double a = stod(b); // 5.4
	double a = stod("44.5"); // 44.5
```

#### stof takes string input and converts it into float
```cpp
	string b = "5.4"; 
	float a = stof(b); // 5.4
	float a = stof("44.5"); // 44.5
```

#### stold takes string input and converts it into long double
```cpp 
	string b = "5008.2934"; 
	long double a = stod(b); // 5008.29
	long double a = stod("44.527462"); // 44.5275
```

### converting int/flaot/double... to string
* using `to_string`
```cpp
	string str = to_string(int val);
	string str = to_string(unsigned val);
	string str = to_string(long val);
	string str = to_string(unsigned long val);
	string str = to_string(long long val);
	string str = to_string(unsigned long long val);
	string str = to_string(float val);
	string str = to_string(double val);
	string str = to_string(long double val);

	string stri = to_string(20388888); //20388888
	string strf = to_string(30.5034485); //30.503448
```