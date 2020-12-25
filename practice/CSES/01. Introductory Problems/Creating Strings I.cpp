#include <iostream>
#include <set>
using namespace std;

#define DEB(x) cout << #x << "==>" << x << endl;
typedef long long ll;
typedef unsigned long long ull;

set<string> st;
void permutations(string &str, int start, int end) {

	if(start == end) {
		st.insert(str);
		return;
	}
	for (int i = start; i <= end; i++) {
		swap(str[start], str[i]);
		permutations(str, start + 1, end);
		swap(str[start], str[i]);
	}

}

void solve() {
	string str; cin >> str;
	permutations(str, 0, str.size() - 1);
	cout << st.size() << endl;
	for(auto it: st) {
		cout << it << endl;
	}
}
 
int main() {
	solve();
	return 0;
}

// string ABCD would have N! permutations i.e. 4! in case of ABCD
// In case of duplicate AABCDEEEFG total would be N! but 
// it will have duplicates
// to remove duplicates the final ans would be (N!) / (2! * 3!)