#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using ppi = pair<int, pi>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second

const int MAX_CHAR = 256;
const int MOD = 1000000007;

vector<vector<int>> tree(2e5 + 1, vector<int>(0));
vector<int> dp(2e5 + 1, 0);

int solve(int curr, int parent) {
    if (tree[curr].size() == 0) return 0;
    if (dp[curr] != 0) return dp[curr];

    int subordinates = 0;
    for (int i: tree[curr]) {
        if (i != curr) {
            subordinates += (1 + solve(i, curr));
        }
    }

    return dp[curr] = subordinates;
}
 
int main() {
    int n; cin >> n;
    int parent;
    for (int i = 2; i <= n; i++) {
        cin >> parent;
        tree[parent].push_back(i);
    }

    solve(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    return 0;
}