#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

class Solution {

public:
    void print_subsets(string input, string output) {
        if (input.length() == 0) {
            DEB(output);
            return;
        }

        string op1 = output;
        string op2 = output + input[0];
        input.erase(input.begin() + 0);

        print_subsets(input, op1);
        print_subsets(input, op2);
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    string input = "abc";
    string output = "";
    SOL->print_subsets(input, output);
    
    delete SOL;
    return 0;
}
