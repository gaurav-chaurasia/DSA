#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    int subset_sum(vector<int> arr, int sum)
    {
        int n = arr.size();
        bool dp[n + 1][sum + 1];

        for(int i = 0, j = 0; j <= sum; j++) dp[i][j] = false;
        for(int i = 0, j = 0; i <= n; i++) dp[i][j] = true;

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= sum; j++)
            {
                // if current element is smaller then the total sum
                // here current element is arr[i - 1]
                // sum is j
                if (arr[i - 1] <= j)
                {
                    // answer dp[i][j] is the or of 
                    // when we include the element in total sum 
                    // and when we don't include element in total sum
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    // if the current element is more then the target sum 
                    // then we can not include that in total sum
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

    vector<int> arr = {2, 5, 8, 7, 15};
    int sum; cin >> sum;
    DEB(SOL->subset_sum(arr, sum));

    delete SOL;
    return 0;
}
