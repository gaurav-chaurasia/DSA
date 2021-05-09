#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    // this problem is to find the length of 
    // shortest common super sequence 
    int shortest_common_super_sequence(int n, string str1, int m, string str2)
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

        return str1.size() + str2.size() - dp[n][m];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int n = S1.size();
    int m = S2.size();
    DEB(SOL->shortest_common_super_sequence(n, S1, m, S2));

    delete SOL;
    return 0;
}
