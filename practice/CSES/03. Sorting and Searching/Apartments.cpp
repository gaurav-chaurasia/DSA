#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]" << endl;
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

int allotment(const vector<int>& ds, const vector<int>& s, int k) {
	int count = 0;
	int i = ds.size() - 1, j = s.size() - 1;
	while (true) {
		if (i < 0 || j < 0) 
			break;

		if (s[j] <= ds[i] + k and s[j] >= ds[i] - k) {
			++count;
			j--;
			i--;
		} else if (s[j] > ds[i] + k) {
			j--;
		} else if (s[j] < ds[i] - k) {
			i--;
		}
	}
	return count;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> ds(n), s(m);
	for (int i = 0; i < n; i++) {
		cin >> ds[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	sort(ds.begin(), ds.end());
	sort(s.begin(), s.end());
	cout << allotment(ds, s, k) << endl; 
}
 
int main() {
	solve();
    return 0;
}
