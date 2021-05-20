#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int current = 0, n, k;
	    cin >> n >> k;
	    int p[n];
	    for (int i = 0; i < n; i++) {
	       cin >> p[i];
	       //sum += p[i];
	    }
	    for (int i = 0; i < n; i++) {
	        if (p[i] > k)
    	        current = current + (p[i] - k);
	    }
	    cout << current << endl;
	}
	return 0;
}
