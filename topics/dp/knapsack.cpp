#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

#define ROW 10e6;
#define COL 10e6;
int dp[ROW][COL];

class Solution {

public:
    /**
     * 0/1 Knapsack recursive code
     * 
     * */ 
    int knapsack(vecotr<int> wt, vector<int> val, int w, int n) {
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
    int knapsack_dp(vecotr<int> wt, vector<int> val, int w, int n) {
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
    int knapsack_td(vecotr<int> wt, vector<int> val, int w, int n) {
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

    int ANS01 = SOL->knapsack();
    int ANS02 = SOL->knapsack_dp();
    int ANS03 = SOL->knapsack_td();
    // SOL1->SOL_03();
    // SOL1->SOL_04();
    
    delete SOL;
    return 0;
}
