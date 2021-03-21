#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define w(x)   int x; cin>>x; while(x--)
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    int SOL_01() {
        int n, k; cin >> n >> k;
        string str; cin >> str;

        int res = 0;
        int j = 0;
        for (int i = 0; i < n / 2; i++) {
            j = n-i-1;
            if (str[i] != str[j])
                res++;
        }
        return abs(k-res);
    }

};

 
int main() {
    Solution* SOL = new Solution();
    int n; cin >>n;
    for (int i = 1; i <= n; i++) {
        int res = SOL->SOL_01();
        cout << "Case #" << i << ": " << res << endl;
    }
    
    delete SOL;
    return 0;
}
