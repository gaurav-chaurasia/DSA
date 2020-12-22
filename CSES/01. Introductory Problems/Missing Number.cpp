#include <iostream>
using namespace std;

int main() {
	long long int n; cin >> n;
	long long int ans = 0;
	for (int i = 0; i < n-1; i++) {
		long long int temp; cin >> temp;
		ans = ans + temp;
	}
	cout << (long long)(n*(n+1)/2) - ans << endl;
	return 0;
}
