#include <bits/stdc++.h>

using namespace std;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

class Solution {

public:
    void print_one_to_n(int n) {
        if (n <= 1) {
            DEB(n);
            return;
        }

        print_one_to_n(n - 1);
        DEB(n);
    }
    
    void print_n_to_one(int n) {
        if (n <= 1) {
            DEB(n);
            return;
        }

        DEB(n);
        print_n_to_one(n - 1);
    }
};

 
int main() {
    Solution* SOL = new Solution();

    SOL->print_one_to_n(11);
    cout << endl;
    SOL->print_n_to_one(11);

    delete SOL;
    return 0;
}
