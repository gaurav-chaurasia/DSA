#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]\n";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    int COIN_CHANGE_1(vector<int> coin, int sum)
    {
        int n = coin.size();
        int dp[n + 1][sum + 1];

        for (int i = 0, j = 0; j <= sum; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (coin[i - 1] <= j)
                    dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
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

    // you are given coins that you have and
    // taking them any number of times you can get a total given sum
    //
    // coin[] = [1, 2, 3]
    // sum = 5;
    // 1 + 1 + 1 + 1 + 1 = [5]
    //     1 + 1 + 1 + 2 = [5]
    //         1 + 2 + 2 = [5]
    //         1 + 1 + 3 = [5]
    //             2 + 3 = [5]
    // in above example there are five ways we can make that sum for coin array

    vector<int> coin = {1, 2, 3};
    int sum = 5;
    DEB(SOL->COIN_CHANGE_1(coin, sum));

    delete SOL;
    return 0;
}
