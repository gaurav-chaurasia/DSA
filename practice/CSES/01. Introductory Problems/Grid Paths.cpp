#include <iostream>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

string str;
int count;
bool vis[7][7]; // do not visite any visited cell

bool is_visited(int x, int y) {
	return vis[x][y];
}
bool is_inside(int x, int y) {
	return x >= 0 and x < 7 and y >= 0 and y < 7;
}
bool e(int x, int y) {
	return is_inside(x, y) and !is_visited(x, y);
}

void dfs(int i, int j, int a = 0) {
	// DEB(i); DEB(j); NL();
	// if you are at end cell 
	if (i == 6 and j == 0) {
		// if you used complete 48 char to reach end
		if (a == 48) {
			++count;
		}
		return;
	}

	// visite (i, j) cell
	vis[i][j] = 1;
	if (str[a] == '?' or str[a] == 'L') {
		if(j and !vis[i][j-1]) {
			if(!(!e(i, j-2) && e(i+1, j-1) && e(i-1, j-1)))
			dfs(i, j-1, a + 1);
		}
	}

	if (str[a] == '?' or str[a] == 'R') {
		if(j < 6 and !vis[i][j+1]) {
			if(!(!e(i, j+2) && e(i+1, j+1) && e(i-1, j+1)))
			dfs(i, j+1, a + 1);
		}
	}

	if (str[a] == '?' or str[a] == 'U') {
		if(i and !vis[i-1][j]) {
			if(!(!e(i-2, j) && e(i-1, j+1) && e(i-1, j-1))) 
			dfs(i-1, j, a + 1);
		}
	}
	
	if (str[a] == '?' or str[a] == 'D') {
		if(i < 6 and !vis[i+1][j]) {
			if(!(!e(i+2, j) && e(i+1, j+1) && e(i+1, j+1))) 
			dfs(i+1, j, a + 1);
		}
	}
	vis[i][j] = 0;
}

void solve() {
	cin >> str;

	// doing dfs on grid and count each good combination
	// good combination which end at (7, 7) cell
	dfs(0, 0);
	cout << count << endl;
}
 
int main() {
	solve();
	return 0;
}
