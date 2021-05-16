#include<iostream>
using namespace std;

void solve() {
	int n; cin >> n;
	if (n == 2 or n == 3) {
		cout << "NO SOLUTION" << endl;
		return;
	}

	for (int i = 2; i <= n; i += 2)
		cout << i << " ";

	for (int i = 1; i <= n; i += 2) 
		cout << i << " ";

	cout << endl;
	return;
}

int main() {
	solve();
	return 0;
}
