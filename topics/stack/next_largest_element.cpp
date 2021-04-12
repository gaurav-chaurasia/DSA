#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define w(x)   int x; cin>>x; while(x--)
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    // find nearest larget element to right
    // AKA Next Largest Element
    // naive approach will take O(n * n) time 
    // while with the help of stack ds we can optimise it 
    // to -> O(n) time complexity
    vector<int> NLE_Right(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> v;

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                v.push_back(-1);
            }
            else if (st.size() > 0 and st.top() > arr[i]) {
                v.push_back(st.top());
            }
            else {
                while (st.size() > 0 and st.top() <= arr[i])
                    st.pop();

                v.push_back(st.size() == 0 ? -1 : st.top()); 
            }
            st.push(arr[i]);
        }

        reverse(v.begin(), v.end());
        return v;
    }

    // find nearest larget element to left
    // AKA Next Largest Element
    // naive approach will take O(n * n) time 
    // while with the help of stack ds we can optimise it 
    // to -> O(n) time complexity
    vector<int> NLE_Left(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> v;

        for (int i = 0; i < n; ++i) {
            if (st.empty()) {
                v.push_back(-1);
            }
            else if (st.size() > 0 and st.top() > arr[i]) {
                v.push_back(st.top());
            }
            else {
                while (st.size() > 0 and st.top() <= arr[i])
                    st.pop();

                v.push_back(st.size() == 0 ? -1 : st.top()); 
            }
            st.push(arr[i]);
        }

        return v;
    }
};

 
int main() {
    Solution* SOL = new Solution();
    
    w(t) {
        vector<int> input = {1, 3, 2, 4};
        vector<int> r = SOL->NLE_Right(input);
        vector<int> l = SOL->NLE_Left(input);
        
        for (auto it: r) cout << it << " ";
        cout << endl;
        for (auto it : l) cout << it << " ";
    }
    
    delete SOL;
    return 0;
}
