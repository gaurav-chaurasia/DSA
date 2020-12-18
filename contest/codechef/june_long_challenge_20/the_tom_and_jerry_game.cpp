#include <bits/stdc++.h>
using namespace std;
 
typedef long long int          ll;
typedef unsigned long long int ull;
 
ull solve() {
    ull ts = 0, js = 0;
    cin >> ts;
    if (ts%2 == 1) // odd
        return floor(ts/2);
    else {
        while (ts % 2 != 1)
            ts /= 2;
        return floor(ts/2);
    }
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       cout << solve() << endl;
    }   
    return 0;
}
