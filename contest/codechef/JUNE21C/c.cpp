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
#define MOD 1000000007

ll power(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % MOD;

        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    ll ans;
    ans = power(2, n);
    ans -= 1;
    ans = power(ans, m);
    cout << ans << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    w(t){
       solve();
    }

    return 0;
}