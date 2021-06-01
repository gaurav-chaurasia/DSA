#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

class Solution {
    public:
    void SOL_01() {
        // your code goes here!!!
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int mn = abs(a - c) + abs(b - d);
        if (k >= mn and (k - mn) % 2 == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
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
