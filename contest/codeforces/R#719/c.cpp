#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define w(x)   int x; cin>>x; while(x--)
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    void SOL_01() {
        int n; cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            return;
        }
        if (n == 2) {
            cout << -1 << endl;
            return;
        }

        vector<vector<int>> matrix(n, vector<int>(n));
        stack<int> st;
        for (int i = 1; i <= n*n; i += 2) {
            st.push(i);
        }
        for (int i = 2; i <= n * n; i += 2) {
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = st.top();
                st.pop();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* SOL = new Solution();
    
    w(t) {
       SOL->SOL_01();
    }
    
    delete SOL;
    return 0;
}
