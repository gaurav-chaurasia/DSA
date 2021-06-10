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
    void generate_all_balanced_parentheses(int open, int close, string op) {
        // base case
        if (open == 0 && close == 0) {
            cout << "[ " << op << " ]\n";
            return;
        }

        // as long as we have openning brackets 
        // we can always call chose openning bracket
        if (open != 0) {
            generate_all_balanced_parentheses(open - 1, close, op + "(");
        }

        // but closing brackets only can be chosen when 
        // number of closing baracket are more because that means 
        // we have used more opening brackets already so 
        // in output string there will be opening brackets to balance them
        if (close > open) {
            generate_all_balanced_parentheses(open, close - 1, op + ")");
        }
        return;
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    SOL->generate_all_balanced_parentheses(3, 3, "");
    
    delete SOL;
    return 0;
}
