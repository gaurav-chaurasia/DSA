#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using ppi = pair<int, pi>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define endl '\n'

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int edit_distance(string a, int n, string b, int m) {
    if (n == 0) return m;
    if (m == 0) return n;
    
    if (a[n - 1] == b[m - 1]) {
        return edit_distance(a, n - 1, b, m - 1);
    }
    else {
        return 1 + min(edit_distance(a, n, b, m - 1), 
        edit_distance(a, n - 1, b, m), 
        edit_distance(a, n - 1, b, m - 1));
    }
}

int edit_distance_memo(string a, int n, string b, int m, vector<vector<int>> &dp) {
    if (n == 0) return m;
    if (m == 0) return n;

    if (dp[n - 1][m - 1] != -1) return dp[n - 1][m - 1];

    if (a[n - 1] == b[m - 1]) {
        return dp[n - 1][m - 1] = edit_distance(a, n - 1, b, m - 1);
    }
    else {
        // dp[n][m - 1] = dp[n][m - 1] != -1 ? dp[n][m - 1] : edit_distance(a, n, b, m - 1);
        // dp[n - 1][m] = dp[n - 1][m] != -1 ? dp[n - 1][m] : edit_distance(a, n - 1, b, m);
        // dp[n-1][m-1] = dp[n-1][m-1] != -1 ? dp[n-1][m-1] : edit_distance(a, n-1, b, m-1);
        return dp[n - 1][m - 1] = 1 + min(
                                            edit_distance(a, n, b, m - 1), 
                                            edit_distance(a, n - 1, b, m), 
                                            edit_distance(a, n-1, b, m-1));
    }
}

int edit_distance_td(string a, int n, string b, int m) {
    int dp[n + 1][m + 1];

    for (int i = 0, j = 0; j <= m; j++) dp[i][j] = j;
    for (int i = 0, j = 0; i <= n; i++) dp[i][j] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    string a; cin >> a;
    string b; cin >> b;
    vector<vector<int>> dp(5001, vector<int>(5001, -1));

    // cout << edit_distance(a, a.size(), b, b.size()) << endl;
    // cout << edit_distance_memo(a, a.size(), b, b.size(), dp) << endl;
    cout << edit_distance_td(a, a.size(), b, b.size()) << endl;
    return 0;
}
