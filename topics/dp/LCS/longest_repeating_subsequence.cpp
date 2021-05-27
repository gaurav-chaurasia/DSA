#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    // string a = "AABEBCDD" --> we can see that 
    // the longest repeating subsequence is ABD  
    void longest_repeating_subsequence(int n, string a) {
        string b = a;
        int m = n;

        dp[n + 1][m + 1];

        for (int i = 0, j = 0; j <= m; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1] and i != j) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        // length of longest repeating subsequence
        cout << dp[n][m] << endl;
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



