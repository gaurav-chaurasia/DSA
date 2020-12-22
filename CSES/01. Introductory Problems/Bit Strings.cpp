#include <iostream>
using namespace std;

#define MOD 1000000007
typedef long long int ll;

void solve(int a) {
	ll ans = 1;
	while(a--) {
		ans = (ans*2) % MOD;
	}
	cout << ans << endl;
}

int main() {
	int n; cin >> n;
	solve(n);
	return 0;
}
