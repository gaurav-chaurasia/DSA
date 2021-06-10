#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

class Solution {

public:
    stack<int> insert_element_in_sorted_stack(stack<int> st, int temp) {
        if (st.size() == 0 || st.top() <= temp) {
            st.push(temp);
            return st;
        }

        int last_element = st.top();
        st.pop();
        st = insert_element_in_sorted_stack(st, temp);
        st.push(last_element);

        return st;
    }

    stack<int> sort_stack_using_recursion(stack<int> st) {
        if (st.size() <= 1) // already sorted
            return st;
        int last_element = st.top();
        st.pop();
        st = sort_stack_using_recursion(st);
        
        return insert_element_in_sorted_stack(st, last_element);
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
    st = SOL->sort_stack_using_recursion(st);

    while (!st.empty())
    {
        DEB(st.top());
        st.pop();
    }

    delete SOL;
    return 0;
}
