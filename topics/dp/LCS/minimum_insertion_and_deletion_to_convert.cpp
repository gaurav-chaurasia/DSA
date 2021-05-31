#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]" << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    // problem
    // min insertion and deletion to convert string a to string b
    // example
    // a = "heap";  b = "pea";
    // adding 'p' in a at the begging and removing 'h' and 'p' 
    void minimum_insertion_and_deletion_to_convert(int n, string str1, int m, string str2)
    {
        int dp[n + 1][m + 1];

        for (int i = 0, j = 0; j <= m; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        // total num of deletions and addition would be 
        int deletions = abs((int)str1.size() - dp[n][m]);
        int additions = abs((int)str2.size() - dp[n][m]);

        DEB(additions);
        DEB(deletions);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();
    
    string S1 = "heap";
    string S2 = "pea";
    int n = S1.size();
    int m = S2.size();
    SOL->minimum_insertion_and_deletion_to_convert(n, S1, m, S2);

    delete SOL;
    return 0;
}
