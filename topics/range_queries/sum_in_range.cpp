#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

const int MAX_CHAR = 256;
const int MOD = 1000000007;

class Solution {

public:
    vector<int> pre_compute(vector<int> arr) {
        vector<int> prefix(arr.size() + 1, 0);
        
        for (int i = 1; i <= arr.size(); ++i) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }

        return prefix;
    }


    // here in this problem 
    // u will be given a array and you have to ans 
    // Q queries 
    // in each query u have to give the sum in array from a to b => [a, b] 
    void sum_query(vector<int> arr, int Q) {
        vector<int> prefix = pre_compute(arr);
        int a, b;

        while(Q--) {
            cin >> a >> b;
            DEB(a);DEB(b);
            cout << " : ";
            DEB(prefix[b + 1] - prefix[a]);
            cout << endl;
        }
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    vector<int> arr = {1, 3, 4, 8, 6, 1, 4, 2};
    SOL->sum_query(arr, 10);
    
    delete SOL;
    return 0;
}
