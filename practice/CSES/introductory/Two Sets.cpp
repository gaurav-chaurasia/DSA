#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

ll sumTill(ll n) {
        return n * (n + 1) / 2;
}

void solve(ll a) {
        ll sum = sumTill(a);
        ll half = sum / 2;
	ll count = 0;
	ll len = a;
        if (sum & 1) {
                cout << "NO" << endl;
                return;
        }
        vector<bool> num(a+1, true);
        while (true) {
                if (half == sum)
                        break;

                if (sum - half > a) {
                        sum = sum - a;
                        num[a] = false;
                        a--; count++;
                } else {
                        num[sum - half] = false;
                        sum = half;
			count++;
                }
        }

        cout << "YES" << endl;
	cout << count << endl;
	for (int i = 1; i <= len; i++) {
		if (!num[i]) 
			cout << i << " ";
	}
	cout << endl << len - count << endl;
	for (int i = 1; i <= len; i++) {
		if (num[i])
			cout << i << " ";
	}
}


int main() {
        int n; cin >> n;
        solve(n);
        return 0;
}
