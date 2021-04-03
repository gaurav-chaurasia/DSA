#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    void SOL_01() {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i]; 

        // store prev ocuurencs and it's index
        unordered_map<int, int> mp(n + 1);
        int i = 1, ans = 0;

        for (int j = 1; j <= n; j++) {
            i = max(i, mp[arr[j]] + 1);
            ans = max(ans, j - i + 1);
            mp[arr[j]] = j;
        }

        cout << (ans) << endl;
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    SOL->SOL_01();
    
    delete SOL;
    return 0;
}
