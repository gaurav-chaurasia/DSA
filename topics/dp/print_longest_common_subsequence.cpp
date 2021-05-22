#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]\n";

class Solution
{

public:
    // LCS
    // returns the length of LCS
    string longest_common_subsequence_td(int n, string str1, int m, string str2)
    {
        int dp[n + 1][m + 1];
        
        for (int i = 0, j = 0; j <= m; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = n, j = m;
        string ans;
        while (i > 0 and j > 0) 
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                    j--;
                else
                    i--;
            }
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
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
    DEB(SOL->longest_common_subsequence_td(n, S1, m, S2));

    delete SOL;
    return 0;
}
