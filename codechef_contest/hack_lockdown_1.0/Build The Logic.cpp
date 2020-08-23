#include <bits/stdc++.h>

using namespace std; 
#define sq(a) (a)*(a)
int solve() {
    int n;
    cin >> n;
    return sq(n)-n*floor(n/2);
}
 
int main() {
    int t{0}, ans{0};
    cin >> t;
    while (t--){
       ans = solve();
       cout << ans << endl;
    }   
    return 0;
}
