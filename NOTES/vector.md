## vector class cpp
> imp points about `#include <vector>`


#### 2-D vector
```cpp
    vector <vector<int>> A = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

     /*     B[0][0] B[0][1] B[0][2]    B[1][0] B[1][1] B[1][2]    B[2][0] B[2][1] B[2][2]   */
     B = { {   1,      2,      3   }, {   4,      5,      6   }, {    7,      8,      9   } };
     /*               B[0]                       B[1]                        B[2]           */

    int row = A.size();
    int col = A[0].size();
 
    for (auto AA : A[0]) {
        cout << "-" << AA << "-";
    } cout << endl;
    // -1--2--3-
    
    for (auto AA : A) {
        cout << AA[0] << "--";
        cout << AA[col-1] << endl;
    }
    // 1--3
    // 4--6
    // 7--9
```

#### 2-D vector
```cpp
    vector <vector <char>> chess(4, vector<char>(4));
    // declare 2D vector

    vector <vector <char>> chess(4, vector<char>(4, '@'));
    // declare and intialize 2d vector;
    /*
    @ @ @ @ 
    @ @ @ @ 
    @ @ @ @ 
    @ @ @ @ 
    */ 
```