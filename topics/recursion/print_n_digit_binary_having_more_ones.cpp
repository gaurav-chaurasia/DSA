#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using ppi = pair<int, pi>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second

const int MAX_CHAR = 256;
const int MOD = 1000000007;

class Solution {

public:
    // print a n digit binary number having more ones than zeros
    // in all of its prefixes i.e.
    // 11010  3->one, 2->zero
    // 1101   3->one, 1->zero
    // 110    2->one, 1->zero
    // 11     2->one, 0->zero
    // 1      1->one, 0->zero
    // "11010" is a valid n bit binary number 
    void print_N_digit_binary_number_having_more_ones(string op, int onec, int zeros, int n) {
        if (n == 0) {
            cout << "[ " << op << " ]" << endl;
            return;
        }

        // one we can always use
        print_N_digit_binary_number_having_more_ones(op + "1", onec + 1, zeros, n - 1);
        // zeros we can only use if once more than zeros
        if (onec > zeros) {
            print_N_digit_binary_number_having_more_ones(op + "0", onec, zeros + 1, n - 1);
        }
    }
};

 
int main() {
    Solution* SOL = new Solution();
    
    SOL->print_N_digit_binary_number_having_more_ones("", 0, 0, 5);
    
    delete SOL;
    return 0;
}
