// divisibility_problem
#include <iostream>

using namespace std;

int solve() {
	int a, b;
	cin >> a >> b;
	if (b % a == 0) return 0;
	else {
		return b - (a % b);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cout << solve() << endl;
	}
}