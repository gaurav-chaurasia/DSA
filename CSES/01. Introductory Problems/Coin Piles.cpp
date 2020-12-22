#include<iostream>
using namespace std;

typedef long long int ll;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		if ((a + b) % 3 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}	
