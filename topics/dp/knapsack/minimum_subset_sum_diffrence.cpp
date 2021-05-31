#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    int minimum_subset_sum_difference(vector<int> arr)
    {
        int n = arr.size();
        int sum = 0;
        for (int i: arr)
            sum += i;
         
        bool dp[n + 1][sum + 1];
        for(int i = 0, j = 0; j <= sum; j++) dp[i][j] = false;
        for(int i = 0, j = 0; i <= n; i++) dp[i][j] = true;

        // max possible sum could be from 0 to total sum 
        // | S1 - S2 |min ===> | total_sum - 2xS1 | min
        // we can find all possible sum from 0 to total sum 
        // and check the min form above formula
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        int ans = INT_MAX;
        for (int i = n, j = 1; j <= sum; j++) 
        {
            if (dp[i][j])
            {
                ans = min(ans, abs(sum - 2*j));
            }
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    vector<int> arr = {1, 6, 11, 5, 2, 5};
    DEB(SOL->minimum_subset_sum_difference(arr));

    delete SOL;
    return 0;
}
