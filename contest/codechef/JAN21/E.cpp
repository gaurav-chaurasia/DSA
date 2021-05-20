#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

ll dp[4020][4020];
ll pref[4020];

ll f2(ll idx, ll taken, ll n, ll k, vector<ll> &a) {
	if (taken >= k and (pref[idx] - taken >= k)) return 0;
	else if (idx >= n) return 1e10;
	else if (dp[idx][taken] != -1) return dp[idx][taken];

	ll c1 = f2(idx+1, min(taken+a[idx], pref[idx]-taken), n, k, a);
	ll c2 = f2(idx+1, min(pref[idx]-taken+a[idx], taken), n, k, a);

	return dp[idx][taken] = 1 + min(c1, c2);
}

ll f1(vector<ll> &a, ll n, ll k) {
	for (int i = 0; i < n / 2; i++) swap(a[i], a[n-i-1]);
	for (int i = 0; i <= n + 10; i++) {
		pref[i] = 0;
		for (int j = 0; j <= k + 10; j++) dp[i][j] = -1;
	}
	for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
	ll ans = f2(0, 0, n, k, a);
	return ans > 1e9 ? -1 : ans;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());
	if (n == 1) {
		cout << "-1" << endl;
		return;
	}
	cout << f1(a, n, k) << endl;
}
 
int main() {
    int t; cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
