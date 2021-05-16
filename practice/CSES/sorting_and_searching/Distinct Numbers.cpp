#include <iostream>
#include <set>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]" << endl;
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	set<int> st;
	int n, temp; cin >> n;
	while (n--) {
		cin >> temp;
		st.insert(temp);
	}

	cout << st.size() << endl;
}
 
int main() {
	solve();
    return 0;
}
