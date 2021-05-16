#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin >> x; while (x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define MOD 1000000007

class Solution
{

public:
    void SOL_01()
    {
        int n; cin >> n; 
        char grid[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if (i == 0 and j == 0 and grid[i][j] == '*') {
                    cout << 0 << endl;
                    return;
                }
            }
            
        int dp[n + 1][n + 1];
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;
        for (int i = 0, j = 0; j <= n; j++) dp[i][j] = 0;
        
        dp[1][1] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 and j == 1)
                    continue;

                if (grid[i - 1][j - 1] == '*') {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
                }
            }
        }

        cout << dp[n][n] << endl; 
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    SOL->SOL_01();

    delete SOL;
    return 0;
}
