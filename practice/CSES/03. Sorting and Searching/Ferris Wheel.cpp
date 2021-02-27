#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	// your code goes here!!!
	int n, x; cin >> n >> x;
	vector<int> p(n), b;
	vector<vector<int>> a;

	for (int i = 0; i < n; i++)
		cin >> p[i];

	sort(p.begin(), p.end(), greater<int>());
	int curr_sum = 0, count = 1;
	for (int i = 0; i < n; i++) {}
	cout << count << endl;
}
 
int main() {
	solve();
    return 0;
}
