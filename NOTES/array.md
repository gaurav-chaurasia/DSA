## array class cpp and general
> imp points about `#include <array>`


> declare 1D & 2D array statically
```cpp
	// 1D
	int    arr[SIZE];
	char   arr[SIZE];
	string arr[SIZE];

	// 2D
	int    arr[ROW][COL];
	char   arr[ROW][COL];
	string arr[ROW][COL];

```

> declare 1D array dynamically
```cpp
	#define SIZE 100

	// char array
	char* chess = new char [SIZE];
	for (int i=0; i < SIZE; i++) {
		chess[i] = 'some char';
	}

	// int array
	int* chess = new int [SIZE];
	for (int i=0; i < SIZE; i++) {
		chess[i] = "some num";
	}

```

> declare 2D array dynamically
```cpp
	#define SIZE 100

	// char array
	char** chess = new char* [SIZE];
	for (int i=0; i < SIZE; i++) {
		chess[i] = new char [SIZE];
	}

	// int array
	int** chess = new int* [SIZE];
	for (int i=0; i < SIZE; i++) {
		chess[i] = new int [SIZE];
	}

```