#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    void SOL_01() {
        int n, x; cin >> n >> x;
        vector<int> arr(n);
        vector<ll> sum(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sum[0] = arr[0];
        for (int i = 1; i < n; i++)
            sum[i] += sum[i-1] + arr[i];

        int res = 0;
        for (vector<ll>::iterator i = sum.begin(); i != sum.end(); i++) {
            if (*i == x)
                res++;
            else if (*i > x) {
                if (binary_search(sum.begin(), i, *i - x))
                    res++;
            }
        }
        cout << res << endl;
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    SOL->SOL_01();
    
    delete SOL;
    return 0;
}
