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
#define MOD 1000000007

class Solution {

public:
    void SOL_01() {
        int sum,n; cin >> n >> sum;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) cin >> arr[i];
        ll dp[sum + 1];

        dp[0] = 1;
        for (int i = 1; i <= sum; i++) {
            dp[i] = 0;

            for (int j: arr) {
                if (i >= j)
                    dp[i] += dp[i - j] % MOD;
            }
        }
        cout << dp[sum] % MOD << endl;
    }
};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* SOL = new Solution();
    
    SOL->SOL_01();
    
    delete SOL;
    return 0;
}
