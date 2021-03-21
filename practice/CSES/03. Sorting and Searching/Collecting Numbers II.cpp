#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution {
    
public:
    /**
     * TLE 
     * also segmentation fault 
    */
    void SOL_01(vector<int> &num, int a, int b) {
        int n = num.size();
        
        vector<bool> arr(n + 1, false);        
        
        // swaping those two numbers
        num[a - 1] = num[a - 1] ^ num[b - 1];
        num[b - 1] = num[a - 1] ^ num[b - 1];
        num[a - 1] = num[a - 1] ^ num[b - 1];

        for (int i = 0; i < n; i++) {
            if (arr[num[i] - 1]) {
                arr[num[i] - 1] = false;
            } 
            arr[num[i]] = true;
        }

        int ans = 0; 
        for (bool it: arr) 
            if (it) 
                ans++;

        cout << ans << endl;
    }
};

int main() {
    Solution* SOL = new Solution();

    int n, m;
    cin >> n >> m;
    vector<int> num(n);

    for (int i = 0; i < n; i++)
        cin >> num[i];

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        SOL->SOL_01(num, a, b);
    }
    // SOL1->SOL_02();
    // SOL1->SOL_03();
    // SOL1->SOL_04();

    return 0;
}
