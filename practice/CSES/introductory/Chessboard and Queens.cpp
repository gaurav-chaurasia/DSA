#include <iostream>
#include <vector>
using namespace std;

#define DEB(x)   cout << "[ " << #x << " ==> " << x << " ]" << endl;
#define NL()     cout << endl;
typedef long long ll;
typedef unsigned long long ull;

#define SIZE 8
int count;

void print_path(vector<vector<bool>> &path) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << path[i][j];
		}
		NL();
	}
}

// @params {path} passed by reference and const so can not be modified 
bool is_safe(int row, int col, const vector<vector<bool>> &path) {
	int i, j;
	
	for (i = 0; i < col; i++) 
		if (path[row][i]) 
	    	return false; 

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (path[i][j]) 
			return false; 
	
 	for (i = row, j = col; j >= 0 && i < SIZE; i++, j--) 
		if (path[i][j]) 
	    	return false; 
 
	return true;
}

void set_queens(char** chess, int col, vector<vector<bool>> &path) {
	if (col >= SIZE) {
		++count;
		return;
	}

	for (int i = 0; i < SIZE; i++) {
		// for (int j = col; j < SIZE; j++) {
			if (is_safe(i, col, path) and chess[i][col] != '*') {
				path[i][col] = true;
				set_queens(chess, col + 1, path);	
				path[i][col] = false;
			}
		// }
	}
	return;
}

void solve() {
	char** chess = new char* [SIZE];
	for (int i=0; i < SIZE; i++) {
		chess[i] = new char [SIZE];
	}

	// take input of 2D array
	for (int row = 0; row < SIZE; row++)
		for (int col = 0; col < SIZE; col++)
			cin >> chess[row][col];

	vector<vector<bool>> path(SIZE, vector<bool>(SIZE, false));
	set_queens(chess, 0, path);
	cout << count << endl;
}

int main() {
	solve();
	return 0;
}
