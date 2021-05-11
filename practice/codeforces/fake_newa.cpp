#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second

class Solution {

public:
    void SOL_01() {
        string str; cin >> str;
        string s = "heidi";

        int i = 0, j = 0;
        while (i < sz(str) and j < sz(s)) {
            if (str[i] == s[j]) {
                i++; j++;
            }
            else
                i++;
        }
        if (j < sz(s)) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
    }

};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* SOL = new Solution();
    
    SOL->SOL_01();
    
    delete SOL;
    return 0;
}
