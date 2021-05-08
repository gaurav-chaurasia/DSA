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
        string str; cin >> str;
        
        vector<char> vec;
        vec.push_back(str[0]);
        for (int i = 1; i < n; i++) {
            if (str[i-1] != str[i]) {
                vec.push_back(str[i]);
            }
        }

        unordered_map<char, bool> mp;
        for (char i: vec) {
            if (mp.find(i) != mp.end()) {
                cout << "NO" << endl;
                return;
            }
            mp[i] = true;
        }
        cout << "YES" << endl;
        return;
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
