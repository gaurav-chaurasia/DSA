#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;

typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    bool equal_sum_partition(vector<int> arr)
    {
        int total_sum = 0;
        for (int i: arr)
            total_sum += i;
        
        // if total sum is odd then return false
        if (total_sum & 1)
            return false;
        
        // below line 
        // we check total_sum / 2 sum is possible or not
        return subset_sum(arr, total_sum >> 1);
    }

    bool subset_sum(vector<int> arr, int sum)
    {
        int n = arr.size();
        int dp[n + 1][sum + 1];
        
        for(int i = 0, j = 0; j <= sum; j++) dp[i][j] = false;
        for(int i = 0, j = 0; i <= n; i++) dp[i][j] = true;

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

        return dp[n][sum];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    vector<int> arr = {1, 5, 5, 11};
    DEB(SOL->equal_sum_partition(arr));

    delete SOL;
    return 0;
}
