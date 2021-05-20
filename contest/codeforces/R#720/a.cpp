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
        ll a, b;
        cin >> a >> b;

        if (b == 1) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << a 
            << " " << a * b 
            << " " << a * (b + 1) 
            << endl;
        }
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
