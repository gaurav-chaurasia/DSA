#include <iostream>
using namespace std;

#define DEB(x) cout << #x << "->" << x << endl;
typedef long long int ll;
typedef unsigned long long ull;

int main() {
	string str;
	cin >> str;
	int start = 0;
	int maxStart = 0;
	int maxEnd = 0;
	int end = 0;
	// int MAX = 1;
	for (unsigned int i = 0; i < str.size(); i++) {
		if (str[start] == str[i]) 
			end = i;
		else {
			start = i;
			end = i;
		}
		// MAX = max((end - start + 1), MAX);
		if ((maxEnd - maxStart + 1) < (end - start + 1)) {
			maxStart = start;
			maxEnd = end;
		}
	}
	DEB(maxStart);
	DEB(maxEnd);
	cout << maxEnd - maxStart + 1 << endl;
} 


// using two pointers finding 
// the start and end index of max sub consicutive string