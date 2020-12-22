#include <iostream>
using namespace std;

typedef long long int ll;

int main() {
	int num; cin >> num;
	int count = 5, ans = 0;
	while(count <= num) {
		ans += num / count;
		count *= 5;
	}
	cout << ans << endl;
}

// things to keep in mind here
//
// for example if we are going with 51
// count of 5 in 51 would be 51/5 ==> 10 
// but we are missing that because of multiple of 5 could also generate 5 i.e. 25, 125, 625,
// because they contain more than one five as composite so we have to count them too
