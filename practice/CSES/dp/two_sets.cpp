#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define endl '\n'

const ll mod = 1000000007;

void solve() {
    ll n; cin >> n;
    ll sum = 0; 
    vector<int> arr(n);
    for (int i = 1; i <= n; i++) {
        sum += i;
        arr[i - 1] = i;
    }

    if (sum % 2 == 1) {
        cout << 0 << endl;
        return;
    }

    sum = sum / 2;
    ll dp[n + 1][sum + 1];

    for (int i = 0, j = 0; j <= sum; j++) dp[i][j] = 0;
    for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
            }
            else {
                dp[i][j] = dp[i - 1][j] % mod;
            }
        }
    }

    cout << (dp[n][sum] * 500000004) % mod << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
