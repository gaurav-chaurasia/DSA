#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

#define ROW 100
#define COL 100
int dp[ROW][COL];

class Solution {

public:
    /**
     * 0/1 Knapsack recursive code
     * 
     * */ 
    int knapsack(vector<int> wt, vector<int> val, int w, int n) {
        if (n == 0 or w == 0) {
            return 0;
        }
        
        if (wt[n-1] <= w) {
            return max(
                val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1),
                knapsack(wt, val, w, n - 1)
            );
        }
        else {
            return knapsack(wt, val, w, n - 1);
        }
    }

    /**
     * Knapsack Memoization code
     * 
     * */
    int knapsack_dp(vector<int> wt, vector<int> val, int w, int n) {
        if (dp[n][w] != -1) {
            return dp[n][w];
        }
        
        if (wt[n-1] <= w) {
            return dp[n][w] = max(
                val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1),
                knapsack(wt, val, w, n - 1)
            );
        }
        else {
            return dp[n][w] = knapsack(wt, val, w, n - 1);
        }
    }

    /**
     * Knapsack top_down
     * 
     * */
    int knapsack_td(vector<int> wt, vector<int> val, int w, int n) {
        // initialize dp
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;
        for (int i = 0, j = 0; j <= w ; j++) dp[i][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                if (wt[i-1] <= j) {
                    dp[i][j] = max(
                                val[i-1] + dp[i-1][j-wt[i-1]],
                                dp[i-1][j]
                            );
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][w];
    }
};

 
int main() {
    Solution* SOL = new Solution();

    // initializing dp with -1
    memset(dp, -1, sizeof(dp));
 
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int weight = 7;
    int n = 4;

    DEB(SOL->knapsack(wt, val, weight, n));
    DEB(SOL->knapsack_dp(wt, val, weight, n));
    DEB(SOL->knapsack_td(wt, val, weight, n));
    
    delete SOL;
    return 0;
}
