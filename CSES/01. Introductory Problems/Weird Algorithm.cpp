#include <iostream>
using namespace std;

void solve(long long int num) {
	while (true) {
		cout << num << " ";
		if (num == 1) {
			break;
		}
		if (num & 1)
			num = num * 3 + 1;
		else 
			num /= 2;
	}
	return;

}



int main() {
	long long int a; cin >> a;
	solve(a);
	return 0;
}
