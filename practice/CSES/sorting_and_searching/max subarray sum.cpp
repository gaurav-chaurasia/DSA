#include <bits/stdc++.h>
using namespace std;
 
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;
 
int main() {
    int n; cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) 
        cin >> vec[i];

    ll ans = INT_MIN;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += vec[i];

        ans = max(sum, ans); 
        
        if (sum < 0) 
            sum = 0;
    }

    cout << ans << endl;
    return 0;
}