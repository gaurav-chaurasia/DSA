#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;

typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    int count_subset_with_given_sum(vector<int> arr, int sum)
    {
        int n = arr.size();
        int dp[n + 1][sum + 1];

        for (int i = 0, j = 0; j <= sum; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 1;
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i -1][j - arr[i -1]] + dp[i - 1][j];
                }
                else 
                {
                    dp[i][j] = dp[i - 1][j];
                }
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

    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int sum; cin >> sum;
    DEB(SOL->count_subset_with_given_sum(arr, sum));
    
    delete SOL;
    return 0;
}
