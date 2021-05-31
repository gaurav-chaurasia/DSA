#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]\n";
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    // min coin to get total = sum
    int COIN_CHANGE_2(vector<int> coin, int sum)
    {
        int n = coin.size();
        int dp[n + 1][sum + 1];

        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;
        for (int i = 0, j = 0; j <= sum; j++) dp[i][j] = INT_MAX - 1;
        for (int i = 1, j = 1; j <= sum; j++) {
            if (j % coin[0] == 0)
                dp[i][j] = j / coin[0];
            else
                dp[i][j] = INT_MAX - 1;
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (coin[i - 1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coin[i - 1]], dp[i - 1][j]);
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    vector<int> coin = {1, 2, 3};
    int sum = 5;
    DEB(SOL->COIN_CHANGE_2(coin, sum));

    delete SOL;
    return 0;
}
