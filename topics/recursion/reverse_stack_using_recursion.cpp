#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

class Solution {

public:
    stack<int> insert_element_bottom_of_stack(stack<int> &st, int temp) {
        if (st.empty()) {
            st.push(temp);
            return st;
        }

        int last_element = st.top();
        st.pop();
        st = insert_element_bottom_of_stack(st, temp);
        st.push(last_element);

        return st;
    }

    stack<int> reverse_stack_using_recursion(stack<int> &st) {
        if (st.size() <= 1) 
            return st;
        
        int last_element = st.top();
        st.pop();
        st = reverse_stack_using_recursion(st);
        st = insert_element_bottom_of_stack(st, last_element);
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
    st = SOL->reverse_stack_using_recursion(st);

    while (!st.empty())
    {
        DEB(st.top());
        st.pop();
    }

    delete SOL;
    return 0;
}
