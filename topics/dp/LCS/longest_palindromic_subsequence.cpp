#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    // if we have one string absdecdiba
    // to find palindromic subsequece we can reverse the string 
    // and find the LCS in those two string
    void longest_palindromic_subsequence(int n, string a, int m, string b) 
    {
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

        cout << "Longest palindromic Subsequence :" << a << endl;
        cout << dp[n][m] << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    string S1 = "abcdgchba";
    string S2 = "abhcgdcba";
    int n = S1.size();
    int m = S2.size();
    SOL->longest_palindromic_subsequence(n, S1, m, S2);

    delete SOL;
    return 0;
}
