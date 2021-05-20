#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

char decode (string s) {
	vector<char> ch(16, 'a');
	for (int i = 1; i < 16; i++) {
		ch[i] += i;
	}
	int first = 1, end = 16;
	for (auto it: s) {
		int temp = (end - first + 1) / 2;
		it == '0' ? end -= temp : first += temp; 
	}
	// DEB(first); DEB(end); NL();
	return ch[first - 1];
}

void solve() {
	int n; cin >> n;
	string str; cin >> str;
	for (int i = 0; i < n/4; i++) {
		cout << decode(str.substr(i*4, 4));
	}
	NL();
}
 
int main() {
    int t; cin >> t;
    while(t--){
       solve();
    }   
    return 0;
}
