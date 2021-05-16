#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

#define DEB(x) cout << #x << "==>" << x << endl;
#define MAX_CHAR 256
typedef long long ll;
typedef unsigned long long ull;


bool is_palindrome_possible(string str) {
	vector<int> count(MAX_CHAR, 0);

	for (auto it: str) {
		count[it]++;
	}

	int odd = 0;
	for (auto it: count) {
		if(it & 1) {
			odd++;
		}

		if(odd > 1)
			return false;
	}

	return true;
}


// get midle element if it present
char get_middle_element(string str) {
	char temp = '\0';
	for(int i = 0; i < str.size(); i++)
		temp = temp ^ str[i];

	return temp;
}

void make_palindrome(string str, int len) {
	if (!is_palindrome_possible(str)) {
		cout << "NO SOLUTION" << endl;
		return;
	}

	// possible
	sort(str.begin(), str.end(), greater<char>());
	deque<char> palindrom;
	
	if (len & 1) {
		char middle_element = get_middle_element(str);
		palindrom.push_back(middle_element);
	}

	for (int i = 0; i < len - 1; i++) {
		if (str.at(i) == str.at(i+1)) {
			palindrom.push_back(str.at(i));
			palindrom.push_front(str.at(i));
			i++;
		}
	}

	for (auto it: palindrom) {
		cout << it;
	}
	cout << endl;
	return;
}

void solve() {
	string str; cin >> str;
	int len = str.size();

	make_palindrome(str, len);
	return;
}

int main() {
	solve();
	return 0;
}
