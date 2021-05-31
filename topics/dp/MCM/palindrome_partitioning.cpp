#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

class Solution {

public:
    // question is 
    // you are given a string 
    // in how many min partitioning you can make all the partitions palindrome
    // nitik ==> in 2 partition 
    // {n}, {iti}, {k} 

    bool is_palindrome(string str, int i, int j) {
        for (int l = i, r = j; l <= r; l++, r--) {
            if (str[l] != str[r])
                return false;
        }
        return true;
    }
    int palindrome_partitioning(string str, int i, int j) {
        if (i >= j || is_palindrome(str, i, j))
            return 0;
        
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp =  palindrome_partitioning(str, i, k) + 
                        palindrome_partitioning(str, k+1, j) + 1;

            ans = min(ans, temp);
        }

        return ans;
    }

    int palindrome_partitioning_memo(string str, int i, int j, vector<vector<int>> &dp) {
        if (i >= j || is_palindrome(str, i, j))
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp = palindrome_partitioning_memo(str, i, k, dp) +
                        palindrome_partitioning_memo(str, k+1, j, dp) + 1;
            
            ans = min(ans, temp);
        }

        return dp[i][j] = ans;
    }

    int palindrome_partitioning_memo_better(string str, int i, int j, vector<vector<int>> &dp) {
        if (i >= j || is_palindrome(str, i, j))
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int left = dp[i][k], 
                right = dp[k + 1][j];
            if (dp[i][k] == -1)
                left = palindrome_partitioning_memo(str, i, k, dp);
            
            if (dp[k + 1][j] == -1)
                right = palindrome_partitioning_memo(str, k+1, j, dp);

                
            int temp = left + right + 1;
            
            ans = min(ans, temp);
        }

        return dp[i][j] = ans;
    }
};

 
int main() {
    Solution* SOL = new Solution();

    DEB(SOL->palindrome_partitioning("nitin", 0, 4));

    vector<vector<int>> dp(1001, vector<int>(1001, -1));
    DEB(SOL->palindrome_partitioning_memo("nitiks", 0, 5, dp));

    delete SOL;
    return 0;
}
