#include<iostream>
#include<vector>
using namespace std;


typedef long long int ll;

int main(){
	int n; cin >> n;
	ll ans = 0;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++) {
		if (arr[i-1] > arr[i]) {
			ans += arr[i-1] - arr[i];
			arr[i] = arr[i-1];
		}
	}
	cout << ans << endl;
	return 0;
}

