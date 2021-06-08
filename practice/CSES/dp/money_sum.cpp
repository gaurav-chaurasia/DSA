#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using ppi = pair<int, pi>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

class Solution {

public:
    void money_sum(int n, int coin[]) {
        int max_sum = 0;
        for (int i = 0; i < n; i++) max_sum += coin[i];

        bool dp[n + 1][max_sum + 1];
        for (int i = 0, j = 0; j <= max_sum; j++) dp[i][j] = false;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= max_sum; j++) {
                if (coin[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - coin[i - 1]] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int count = 0;
        vector<int> sums;
        for (int j = 1; j <= max_sum; j++) {
            for (int i = 1; i <= n; i++) {
                if (dp[i][j]) {
                    count++;
                    sums.push_back(j);
                    break;
                }
            }
        }

        cout << count << endl;
        for (int i: sums) cout << i << " ";
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    int n; cin >> n;
    int coins[n]; 
    for (int i = 0; i < n; i++) cin >> coins[i];
    SOL->money_sum(n, coins);
    
    delete SOL;
    return 0;
}
