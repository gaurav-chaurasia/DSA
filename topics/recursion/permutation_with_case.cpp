#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

class Solution {

public:
    void permutation_with_case_change(string ip, string op) {
        if (ip.empty()) {
            DEB(op);
            return;
        }

        string op1 = op, op2 = op;
        op1.push_back(ip[0]);
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin() + 0);

        permutation_with_case_change(ip, op1);
        permutation_with_case_change(ip, op2);
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    string in = "abc";
    string out = "";
    SOL->permutation_with_case_change(in, out);
    
    delete SOL;
    return 0;
}
