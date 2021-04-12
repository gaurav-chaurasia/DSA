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
        int n, k;
        string str;
        cin >> n >> k >> str;

        int count = 0;
        int count_char = 0;
        for (int i = 0; i < n;i++) {
            if (str.at(i) == '*') {
                count++;
            }
            else {
                count = 0;
            }
            count_char = max(count_char, count);
        }

        if (count_char >= k) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
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
