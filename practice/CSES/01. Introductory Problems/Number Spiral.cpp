#include <iostream>
using namespace std;

#define DEB(x) cout << #x << "==>" << x << endl;
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	ll x, y; cin >> y >> x;
	ll z = max(x, y);
	ll z2 = (z-1) * (z-1), ans;
	
	if (z % 2) {
		if(y == z) {
			ans = z2 + x;
		} else {
			ans = z2 + 2*z - y;
		}
	} else {
		if (x == z) {
			ans = z2 + y;
		} else {
			ans = z2 + 2*z - x;
		}
	}
	cout << ans << endl;
}
 
int main() {
    int t; cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
