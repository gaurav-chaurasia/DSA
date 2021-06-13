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
    bool parenthese_checker(string str) {
        int n = str.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            char item = str[i];
            char x;

            if (item == '{' || item == '[' || item == '(') {
                st.push(item);
                continue;
            }

            if (st.empty()) 
                return false;

            switch (item) {
                case ')':
                    x = st.top(); st.pop();
                    if (x == '{' || x == '[')
                        return false;
                    break;
                case '}':
                    x = st.top(); st.pop();
                    if (x == '(' || x == '[') 
                        return false;
                    break;
                case ']':
                    x = st.top(); st.pop();
                    if (x == '{' || x == '(') 
                        return false;
                    break;
            }
        }

        return (st.empty());
    }

};

 
int main() {
    Solution* SOL = new Solution();

    string ans = SOL->parenthese_checker("{([])}") ? "Balanced" : "Unbalanced";
    cout << ans << endl;

    delete SOL;
    return 0;
}
