#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]\n";

class Solution
{

public:
    int longest_common_substring(int n, string str1, int m, string str2)
    {
        int dp[n + 1][m + 1];
        int result = INT_MIN;
        for (int i = 0, j = 0; j <= m; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;

                result = max(result, dp[i][j]);
            }
        }

        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    string S1 = "abcdgh";
    string S2 = "abedfhr";
    int n = S1.size();
    int m = S2.size();
    DEB(SOL->longest_common_substring(n, S1, m, S2));

    delete SOL;
    return 0;
}
