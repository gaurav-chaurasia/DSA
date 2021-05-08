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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a;
        int cur = 0;
        for (char c : s) {
            if (c == '.') ++cur;
            else a.push_back(cur);
        }
        if (a.empty()) {
            cout << 0 << '\n';
            return;
        }

        sort(a.begin(), a.end());

        int m = a[a.size() / 2];
        // DEB(m);
        ll ans = 0;
        for (int k : a)
            ans += abs(k - m);
        cout << ans << '\n';
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
