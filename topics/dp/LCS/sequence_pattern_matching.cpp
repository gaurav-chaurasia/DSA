#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    bool sequence_pattern_matching(int n, string a, int m, string b) {
        int dp[n + 1][m + 1];

        for (int i = 0, j = 0; j <= m; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][m] == a.size();
    }

};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* SOL = new Solution();

    string S1 = "abdh";
    string S2 = "abedfhr";
    int n = S1.size();
    int m = S2.size();
    cout << SOL->sequence_pattern_matching(n, S1, m, S2) << endl;
    
    delete SOL;
    return 0;
}
