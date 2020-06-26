/*
let two number be X and Y;
if we write X = G * a1;
            Y = G * a2;
            G is GCD of X and Y
*/

#include <iostream>
using namespace std;


int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    else
        return gcd(a, b-a);
} 

void solve() {
    int X, Y;
    cin >> X >> Y;
    cout << gcd(X, Y);
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       solve();
    }   
    return 0;
}
