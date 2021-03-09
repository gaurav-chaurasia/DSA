/**
 * here things to keep in mind is 
 * in each gondola at max 2 children can go 
 * and total weight should not exceed x
 * 
 * here we will keep weight of childrens into a multiset
 * multiset will keep weights in sorted order
 * **/
#include <iostream>
#include <set> // set and multiset
#include <algorithm>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n, x, t, cur_x = 0; cin >> n >> x;
	multiset<int> p;
	for (int i =0; i < n; i++) {
		cin >> t;
		p.insert(t);
	} 

	int count = 0;
	

	cout << count << endl;
}
 
int main() {
	solve();
	return 0;
}
