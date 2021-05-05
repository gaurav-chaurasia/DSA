#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]\n";

class Solution
{

public:
    // LCS
    // returns the length of LCS
    int longest_common_subsequence(int n, string str1, int m, string str2)
    {
        if (n == 0 or m == 0)
            return 0;
        
        if (str1[n - 1] == str2[m - 1]) 
        {
            return 1 + longest_common_subsequence(n - 1, str1, m - 1, str2);
        }
        else 
        {
            return max(
                longest_common_subsequence(n, str1, m - 1, str2),
                longest_common_subsequence(n - 1, str1, m, str2)
            );
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    string S1 = "abcdgh";
    string S2 = "abedfhr";
    DEB(SOL->longest_common_subsequence(S1.size(), S1, S2.size(), S2));

    delete SOL;
    return 0;
}
