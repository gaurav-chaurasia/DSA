#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]" << endl;
typedef long long ll;
typedef unsigned long long ull;

ll partition(vector<ll> a, int i, ll temp_sum, ll sum) {
	if (i == 0)
		return abs(sum - 2 * temp_sum);

	return min(
			partition(a, i-1, temp_sum + a[i-1], sum),
			partition(a, i-1, temp_sum, sum)
		);
}

void solve() {
	int len; cin >> len;
	ll sum = 0;
	vector<ll> weights(len);
	for (int i = 0; i < len; i++) {
		cin >> weights[i];
		sum += weights[i];
	}

	cout << partition(weights, len, 0, sum) << endl;
}
 
int main() {
	solve();
	return 0;
}
