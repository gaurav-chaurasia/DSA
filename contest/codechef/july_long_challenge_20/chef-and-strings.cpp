#include <bits/stdc++.h>
 
using namespace std;

 
typedef long long ll;
typedef unsigned long long ull;
 
void solve() {
    int n, a, b;
    ll sum =0;
    cin >> n >> a;
    for (int i =0; i < n - 1; i++) {
        cin >> b;
        sum += (ll)(abs(b-a) - 1);
        a = b;
    }
    cout << sum << endl;
    return;
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       solve();
    }   
    return 0;
}
