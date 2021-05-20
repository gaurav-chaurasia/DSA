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
        float k1, k2, k3, v; 
        cin >> k1 >> k2 >> k3 >> v;
        float res = k1 * k2 * k3 * v;

        int ans = round(10000 / res); 

        
        cout << (ans < 958 ? "YES" : "NO") << endl;
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    w(t) {
       SOL->SOL_01();
    }
    
    delete SOL;
    return 0;
}
