#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    bool scrambeled_string(string a, string b) {
        if (a.size() != b.size()) return false;
        if (a.empty() and b.empty()) return true;
        if (a.compare(b) == 0) return true;
        if (a.size() <= 1) return false;

        int n = a.size();
        bool flag = false;

        for (int i = 1; i < n; i++) {
            if (scrambeled_string(a.substr(0, i), b.substr(n - i, i)) and
                    scrambeled_string(a.substr(i, n - i), b.substr(0, n - i)) ||
                scrambeled_string(a.substr(0, i), b.substr(0, i)) and
                    scrambeled_string(a.substr(n - 1, i), b.substr(n - i, i)))
            {
                flag = true;
                break;
            }
        }

        return flag;
    }

    bool scrambeld_string_memo(string a, string b, vector<vector<int>> &dp) {

    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    string S1 = "great";
    string S2 = "ategr";
    string ans1 = SOL->scrambeled_string(S1, S2) ? "Scrambeld" : "Not Scrambeld";
    // string ans2 = SOL->scrambeled_string_memo(S1, S2) ? "Scrambeld" : "Not Scrambeld";
    cout << ans1 << endl;
    // cout << ans2 << endl;

    delete SOL;
    return 0;
}
