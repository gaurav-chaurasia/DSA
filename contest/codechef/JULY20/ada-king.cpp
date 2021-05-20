#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int k;
    cin >> k;
    vector <vector <char>> chess(8, vector<char>(8, '.'));

    for (int i = 0; i < 8; i++) {
        for (int j =0; j < 8; j++) {
            if (k > 0) {
                chess[i][j] = '@';
                k--;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j =0; j < 8; j++) {
            if ( chess[i][j] == '@' and (i+1 < 8 and chess[i+1][j] != '@' ) ) chess[i+1][j] = 'X';
            if ( chess[i][j] == '@' and (j+1 < 8 and chess[i][j+1] != '@' ) ) chess[i][j+1] = 'X';
            if ( chess[i][j] == '@' and (i-1 >= 0 and chess[i-1][j] != '@' ) ) chess[i-1][j] = 'X';
            if ( chess[i][j] == '@' and (j-1 >= 0 and chess[i][j-1] != '@' ) ) chess[i][j-1] = 'X';
            if ( chess[i][j] == '@' and (i+1 < 8 and j-1 >= 0 and chess[i+1][j-1] != '@' ) ) chess[i+1][j-1] = 'X';
            if ( chess[i][j] == '@' and (i-1 >= 0 and j+1 < 8 and chess[i-1][j+1] != '@' ) ) chess[i-1][j+1] = 'X';
            if ( chess[i][j] == '@' and (i+1 < 8 and j+1 < 8 and chess[i+1][j+1] != '@' ) ) chess[i+1][j+1] = 'X';
            if ( chess[i][j] == '@' and (i-1 >= 0 and j-1 >= 0 and chess[i-1][j-1] != '@' ) ) chess[i-1][j-1] = 'X';
        }
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j =0; j < 8; j++) {
            if (chess[i][j] == '@')
                chess[i][j] = '.';
        }
    }

    chess[0][0] = 'O';
    for (int i = 0; i < 8; i++) {
        for (int j =0; j < 8; j++)
            cout << chess[i][j];
        cout << endl;
    }
        
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       solve();
    }   
    return 0;
}
