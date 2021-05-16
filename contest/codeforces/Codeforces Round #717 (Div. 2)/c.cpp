#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second

void solve() {
    ll n, sum = 0; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum & 1) {
        cout << 0 << endl;
        return;
    }
    bool dp[n + 1][(sum / 2) + 1];
    for (int i = 0, j = 0; j <= sum / 2; j++) dp[i][j] = false;
    for (int i = 0, j = 0; i <= n; i++) dp[i][j] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum / 2; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]; 
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    if (dp[n][sum / 2]) {
        while (true) {
            // find odd number
            for (int i = 0; i < n; i++) {
                // if found return the ans
                if (arr[i] & 1) {
                    cout << 1 << endl;
                    cout << i + 1 << endl;
                    return;
                }
            }
            // if odd num not found then divide all nums with one 2
            for (int i = 0; i < n; i++) {
                arr[i] /= 2;
                // if found return the ans
                if (arr[i] & 1) {
                    cout << 1 << endl;
                    cout << i + 1 << endl;
                    return;
                }
            }
        }
    }
    else {
        cout << 0 << endl;
        return;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // w(t){
       solve();
    // }   
    return 0;
}
