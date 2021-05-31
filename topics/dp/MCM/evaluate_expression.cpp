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

int dp[1001][1001][2];

class Solution {
    public:
    // in this problem
    // you are given a string consiste of only {T, F, |, &, ^}
    // you task is to count how many ways it can be evaluated as true

    // explanation 
    // k only can be taken on operators i.e.
    // if we have { T | F & T ^ F }
    // k can be at index 1 -> |,
    // or at index 3 -> &,
    // or at index 5 -> ^ ... so on 
    int evaluate_expression_to_true(string str, int i, int j, bool is_true) {
        // basecase
        if (i > j) 
            return false;
        if (i == j) {
            if (is_true) {
                return str[i] == 'T';
            }
            else {
                return str[i] == 'F';
            }
        }

        int ans = 0;

        for (int k = i + 1; k < j; k += 2) {
            int LT = evaluate_expression_to_true(str, i, k - 1, true);
            int LF = evaluate_expression_to_true(str, i, k - 1, false);
            int RT = evaluate_expression_to_true(str, k + 1, j, true);
            int RF = evaluate_expression_to_true(str, k + 1, j, false);

            if (str[k] == '&') {
                if (is_true) {
                    ans += (LT * RT);
                }
                else {
                    ans += (LF * RT) + (LT * RF) + (LF * RF);
                }
            }
            else if (str[k] == '|') {
                if (is_true) {
                    ans += (LT * RF) + (LF * RT) + (LT * RT);
                }
                else {
                    ans += (LF * RF);
                }
            }
            else if (str[k] == '^') {
                if (is_true) {
                    ans += (LT * RF) + (LF * RT);
                }
                else {
                    ans += (LT * RT) + (LF * RF);
                }
            }
        }

        return ans;
    }

    int evaluate_expression_to_true_memo(string str, int i, int j, bool is_true) {
        if (i > j) {
            return false;
        }
        if (dp[i][j][is_true] != -1) {
            return dp[i][j][is_true];
        }
        if (i == j) {
            if (is_true) {
                return str[i] == 'T';
            }
            else {
                return str[i] == 'F';
            }
        }

        int ans = 0;
        for (int k = i + 1; k < j; k += 2) {
            int LT = (dp[i][k - 1][true] != -1)  ? dp[i][k - 1][true]  : evaluate_expression_to_true(str, i, k - 1, true);
            int LF = (dp[i][k - 1][false] != -1) ? dp[i][k - 1][false] : evaluate_expression_to_true(str, i, k - 1, false);
            int RT = (dp[k + 1][j][true] != -1)  ? dp[k + 1][j][true]  : evaluate_expression_to_true(str, k + 1, j, true);
            int RF = (dp[k + 1][j][false] != -1) ? dp[k + 1][j][false] : evaluate_expression_to_true(str, k + 1, j, false);

            if (str[k] == '&') {
                if (is_true) {
                    ans += (LT * RT);
                }
                else {
                    ans += (LF * RT) + (LT * RF) + (LF * RF);
                }
            }
            else if (str[k] == '|') {
                if (is_true) {
                    ans += (LT * RF) + (LF * RT) + (LT * RT);
                }
                else {
                    ans += (LF * RF);
                }
            }
            else if (str[k] == '^') {
                if (is_true) {
                    ans += (LT * RF) + (LF * RT);
                }
                else {
                    ans += (LT * RT) + (LF * RF);
                }
            }
        }

        return dp[i][j][is_true] = ans;
    }
};

 
int main() {
    Solution* SOL = new Solution();

    string s = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    // string s = "T|F&T^F";
    DEB(SOL->evaluate_expression_to_true(s, 0, s.size()-1, true));

    // memset(dp, -1, sizeof(dp));
    // DEB(SOL->evaluate_expression_to_true_memo(s, 0, s.size()-1, true));

    delete SOL;
    return 0;
}
