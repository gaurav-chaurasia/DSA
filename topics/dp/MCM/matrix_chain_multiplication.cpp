#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

class Solution {

public:
    int matrix_chain_multiplication(vector<int> arr, int i, int j) {
        if (i >= j)
            return 0;
        
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp =  matrix_chain_multiplication(arr, i, k) + 
                        matrix_chain_multiplication(arr, k+1, j) + 
                        arr[i - 1] * arr[k] * arr[j];
            ans = min(ans, temp);
        }

        return ans;
    }

    // memo
    int matrix_chain_multiplication_memo(vector<int> arr, int i, int j, vector<vector<int>> &dp) {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {

            int temp =  matrix_chain_multiplication(arr, i, k) +
                        matrix_chain_multiplication(arr, k + 1, j) +
                        arr[i - 1] * arr[k] * arr[j];

            ans = min(ans, temp);
        }

        return dp[i][j] = ans;
    }
};

 
int main() {
    Solution* SOL = new Solution();
    
    vector<int> arr = {40, 20, 30, 10, 30};
    DEB(SOL->matrix_chain_multiplication(arr, 1, 4));

    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    DEB(SOL->matrix_chain_multiplication_td(arr, 1, 4, dp));
    
    delete SOL;
    return 0;
}
