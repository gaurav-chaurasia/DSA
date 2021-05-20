#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n, k, d, sum = 0, ans;
	cin >> n >> k >> d;
	while(n--) {
		int temp; cin >> temp;
		sum += temp;
	}
	ans = sum / k < d ? sum / k : d;
	cout << ans << endl;
}
 
int main() {
    int t; cin >> t;
    while(t--){
       solve();
    }   
    return 0;
}
