#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define MOD    1000000007
typedef long long ll;
typedef unsigned long long ull;

class Solution {
public:
    // somthing is wrong
    // not correct 😭
    ll SOL_01(int n, vector<ll> &dp) {
        if (dp[n] != 0)
            return dp[n];

        if (n == 0)
            return 1;

        ll sum = 0;
        for (int i = 1; i <= 6 && n - i >= 0; i++) {
            (sum += SOL_01(n - i, dp)) % MOD;
        }
        
        dp[n] = sum;
        return dp[n];
    }

    // okay solution
    // works fine
    ll SOL_02(int n) {
        vector<ll> dp(n + 1, 0);
 
        dp[0] = 1;
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 6 && i - j >= 0; j++) {
                (dp[i] += dp[i - j]) %= MOD;
            }
        }
 
        return dp[n];
    }
};

 
int main() {
    Solution* SOL = new Solution();
    
    int n; cin >> n;
    vector<ll> dp(n + 1, 0);

    // cout << SOL->SOL_01(n, dp) << endl;
    cout << SOL1->SOL_02(n) << endl;
    // SOL1->SOL_03();
    // SOL1->SOL_04();
    
    delete SOL;
    return 0;
}
