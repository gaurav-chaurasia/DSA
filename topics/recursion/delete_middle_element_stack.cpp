#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

class Solution {

public:
    stack<int> delete_middle_element_stack(stack<int> st, int k) {
        if (k == 1) {
            st.pop();
            return st;
        }

        int last_element = st.top();
        st.pop();
        st = delete_middle_element_stack(st, k - 1);
        st.push(last_element);

        return st;
    }

};

 
int main() {
    Solution* SOL = new Solution();

    stack<int> st;
    st.push(10);
    st.push(9);
    st.push(3);
    st.push(12);
    st.push(16);
    st.push(2);
    st.push(120);
    st = SOL->delete_middle_element_stack(st, (st.size()/2) + 1);
    while (!st.empty()) {
        DEB(st.top());
        st.pop();
    }

    delete SOL;
    return 0;
}
