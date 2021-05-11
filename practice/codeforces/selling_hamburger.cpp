#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second

class Solution {

public:
    void SOL_01() {
        ll n; cin >> n;
        vector<ll> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        ll ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ll sum = 0;
            for (int j = 0; j < n; j++) {
                if (arr[i] <= arr[j])
                    sum += 1;
            }
            ans = max(ans, sum * arr[i]);
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
