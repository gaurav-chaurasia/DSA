// #include <bits/stdc++.h>
#include <iostream> 
using namespace std;

#define sq(a)              (a)*(a)

typedef long int               int32;
typedef unsigned long int      uint32;
typedef long long int          int64;
typedef unsigned long long int uint64;

int64 solve() {
    int64 l;
    cin >> l;
    if (l == 1) return 1;
    else return 2*sq(l) + (l-2)*l*2 + sq(l-2)*2;
}
 
int main() {
    int64 t{0}, ans{0};
    cin >> t;
    while (t--){
       ans = solve();
       cout << ans << endl;
    }   
    return 0;
}
