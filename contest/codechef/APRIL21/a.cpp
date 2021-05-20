#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define w(x)   int x; cin>>x; while(x--)
#define ps(x, y) fixed << setprecision(y) << x
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    void SOL_01() {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b || a == c) {
            cout << "YES" << endl;
            return;
        }
        if (b == a || b == c) {
            cout << "YES" << endl;
            return;
        }
        if (c == b || a == c) {
            cout << "YES" << endl;
            return;
        }
        cout << "NO"  << endl;
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    // w(t) {
       SOL->SOL_01();
    // }
    
    delete SOL;
    return 0;
}
