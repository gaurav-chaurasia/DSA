#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	ll n, k, x, y;
	cin >> n >> k >> x >> y;
	vector<pair<ll, ll>> cords;
	if (x > y) {
		cords.push_back(make_pair(n, n + (y - x)));
		cords.push_back(make_pair(n + (y - x), n));
		cords.push_back(make_pair(0, (x - y)));
		cords.push_back(make_pair((x - y), 0));
	} else if (x < y) {
		cords.push_back(make_pair(n - (y - x), n));
		cords.push_back(make_pair(n, n - (y - x)));
		cords.push_back(make_pair((y - x), 0));
		cords.push_back(make_pair(0, (y - x)));
	} else {
		cout << n << " " << n << endl;
		return;
	}
	if (k % 4 == 0) {
		cout << cords[3].first << " " << cords[3].second << endl;
	} else {
		cout << cords[(k % 4) - 1].first << " " << cords[(k % 4) - 1].second << endl;
	}
	return;
} 
 
int main() {
    int t; cin >> t;
    while(t--){
       solve();
    }   
    return 0;
}
