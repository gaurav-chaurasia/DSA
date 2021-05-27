#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    /**
     * below functions count the number of subset with given diff
     * and 
    */
    int count_number_of_subset_with_given_difference(vector<int> arr, int diff)
    {
        int total_sum = 0;
        for (int i: arr) total_sum += i;
        
        // as many subset possible in arr with below sum
        // that many subset will be there with that diffrence
        int sum = (total_sum - diff) / 2;
        return count_of_subset_with_given_sum(arr, sum);
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
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
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

    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;
    DEB(SOL->count_number_of_subset_with_given_difference(arr, diff));
    NL();

    delete SOL;
    return 0;
}
