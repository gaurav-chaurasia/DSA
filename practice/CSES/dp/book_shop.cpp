#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second

class Solution
{

public:
    void SOL_01()
    {
        int n, total;
        cin >> n >> total;

        int price[n];
        int page[n];
        for (int i = 0; i < n; i++) cin >> price[i];
        for (int i = 0; i < n; i++) cin >> page[i];

        int dp[n + 1][total + 1];
        for (int i = 0, j = 0; j <= total; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= total; j++) {
                if (price[i - 1] <= j) {
                    dp[i][j] = max(page[i - 1] + dp[i - 1][j - price[i - 1]], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        cout << dp[n][total] << endl;
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
