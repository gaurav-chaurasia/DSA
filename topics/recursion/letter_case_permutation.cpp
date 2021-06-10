#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

class Solution {

public:
    void letter_case_permutations(string ip, string op) {
        if (ip.empty()) {
            DEB(op);
            return;
        }

        string op1 = op, op2 = op;
        if (ip[0] >= 'a' and ip[0] <= 'z') {
            op1 += ip[0];
            op2 += toupper(ip[0]);
            ip.erase(ip.begin() + 0);
            letter_case_permutations(ip, op1);
            letter_case_permutations(ip, op2);
        }
        else if (ip[0] >= 'A' and ip[0] <= 'Z') {
            op1 += ip[0];
            op2 += tolower(ip[0]);
            ip.erase(ip.begin() + 0);
            letter_case_permutations(ip, op1);
            letter_case_permutations(ip, op2);
        }
        else {
            op += ip[0];
            ip.erase(ip.begin() + 0);
            letter_case_permutations(ip, op);
        }
        return;
    }

};
 
int main() {
    Solution* SOL = new Solution();
    
    string ip = "a1B2c";
    string op = "";
    SOL->letter_case_permutations(ip, op);
    
    delete SOL;
    return 0;
}
