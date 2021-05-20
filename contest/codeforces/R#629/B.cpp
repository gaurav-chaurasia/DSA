// K-th Beautiful String
// youtube video helped: https://youtu.be/bZQDRArWYeI
#include <iostream>
using namespace std;

string solve(int len, int pos) {
	// declare string with all a
	string str(len, 'a');

	// let's find positions of b
	for(int i = len - 2; i >= 0; i--) {
		if (pos <= len - i - 1) {
			str[i] = 'b';
			str[len-pos] = 'b';
			break;
		}
		pos -= (len - i - 1);
	}
	return str;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}
}