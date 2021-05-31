#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    int target_sum(vector<int> arr, int sum)
    {
        int total_sum = 0;
        for (int i: arr) total_sum += i;

        return count_of_subset_with_given_sum(arr, (total_sum - sum) / 2);
    }
    int count_of_subset_with_given_sum(vector<int> arr, int sum)
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
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
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

    vector<int> arr = {1, 1, 2, 3};
    int sum = 1;
    DEB(SOL->target_sum(arr, sum));NL();

    delete SOL;
    return 0;
}
