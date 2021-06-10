#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

class Solution {

public:
    void permutation_with_space(string in, string out) {
        if (in.empty()) {
            DEB(out);
            return;
        }

        if (out.empty()) {
            string t = out + in[0];
            in.erase(in.begin() + 0);
            permutation_with_space(in, t);
            return;
        }

        string op1 = out + " " + in[0];
        string op2 = out + in[0];
        in.erase(in.begin() + 0);

        permutation_with_space(in, op1);
        permutation_with_space(in, op2);
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    string input = "abc";
    string output = "";
    SOL->permutation_with_space(input, output);
    
    delete SOL;
    return 0;
}
