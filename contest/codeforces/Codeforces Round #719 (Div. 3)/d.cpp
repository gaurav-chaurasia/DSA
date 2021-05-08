#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define w(x)   ll x; cin>>x; while(x--)
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    void SOL_01() {
        ll n; cin >> n;
        vector<ll> arr(n);

        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i] = arr[i] - i;
        }
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++) {
            auto it = mp.find(arr[i]);
            if (it != mp.end()) {
                it->second += 1;
                continue;
            }
            mp.insert({arr[i], 1});
        }

        ll ans = 0;
        for (auto i = mp.begin(); i != mp.end(); i++) {
            ll temp = i->second;
            ans += (ll)(temp*(temp-1))/2;
        }

        cout << ans << endl;
    }

};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* SOL = new Solution();
    
    w(t) {
       SOL->SOL_01();
    }
    
    delete SOL;
    return 0;
}
