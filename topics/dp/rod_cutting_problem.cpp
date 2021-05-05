#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]\n";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    // init_length is the length of rod in begining 
    //
    //  __ __ __ __ __
    //  __ __ __ __ __
    //
    // length array is the possible length in which rod can be cut
    // price array is the price for specific length
    // {1, 2, 3, 4, 5,  6,  7,  8};
    // {1, 5, 8, 9, 10, 17, 17, 20};
    int rod_cutting(vector<int> length, vector<int> price, int init_length)
    {
        int n = length.size();
        int dp[n + 1][init_length + 1];

        for (int i = 0, j = 0; j <= init_length; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= init_length; j++)
            {
                if (length[i - 1] <= j)
                {
                    dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
                }
                else 
                {
                    dp[i][j] = dp[i - 1][j];    
                }
            }
        }

        return dp[n][init_length];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    // rod_initial_length
    // initial length of rod before cutting
    //
    // rod_length[] array
    // it containes how many possible size in which we can cut the rod
    // i.e. we can cut the rod of initial length 8
    // 8 --> 1, 1, 2, 4
    // 8 --> 2, 2, 2, 2
    // 8 --> 4, 4
    // 8 --> 1, 1, 1, 1, 1, 1, 1, 1
    // ... so ..on
    //
    // rod_price[] array
    // it containes the price for any length of the array like,
    // 1 len --> price 1
    // 2 len --> price 5
    // 6 len --> price 17
    vector<int> rod_length = {1, 2, 3, 4, 5,  6,  7,  8};
    vector<int> rod_price  =  {1, 5, 8, 9, 10, 17, 17, 20};
    int rod_initial_length = 8;
    DEB(SOL->rod_cutting(rod_length, rod_price, rod_initial_length));

    delete SOL;
    return 0;
}
