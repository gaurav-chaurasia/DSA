/**
 * 
 *  https://youtu.be/p9T-fE1g1pU?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd
 * 
    The stock span problem is a financial problem where 
    we have a series of n daily price quotes for a stock and 
    we need to calculate span of stock’s price for all n days. 
    The span Si of the stock’s price on a given day i is defined as 
    the maximum number of consecutive days just before the given day, 
    for which the price of the stock on the current day is less than or 
    equal to its price on the given day.
 * 
 * 
*/
#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define w(x)   int x; cin>>x; while(x--)
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    vector<int> SSP(vector<int> arr) {
        int n = arr.size();
        vector<int> v;
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                v.push_back(i + 1);
            }
            else if (!st.empty() && st.top().first > arr[i]) {
                v.push_back(i - st.top().second);
            }
            else {
                while (!st.empty() && st.top().first <= arr[i]) st.pop();

                v.push_back(st.empty() ? (i + 1) : i - st.top().second);
            }
            st.push({arr[i], i});
        }
        return v;
    }
};

 
int main() {
    Solution* SOL = new Solution();
    
    w(t) {
        vector<int> input = {100, 80, 60, 70, 60, 75, 85};
        vector<int> r = SOL->SSP(input);
        
        for (auto it: r) cout << it << " ";
        cout << endl;
    }
    
    delete SOL;
    return 0;
}
