#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << x << " ]\n";

class Solution {

public:
    int kth_symbol_in_grammer(int n, int k) {
        if (n == 1 and k == 1) return 0;
        
        int mid = pow(2, n - 2);
        if (k <= mid) {
            return kth_symbol_in_grammer(n - 1, k);
        }
        else {
            return !kth_symbol_in_grammer(n - 1, k - mid);
        }
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    DEB(SOL->kth_symbol_in_grammer(4, 3));
    
    delete SOL;
    return 0;
}
