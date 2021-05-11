#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second

class Solution {

public:
    void SOL_01() {
        int n; cin >> n;
        vector<int> arr(n), ans;
        stack<pi> st;

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                cout << 0 << " ";
            }
            else if (st.top().f < arr[i]) {
                cout << st.top().second << " ";
            }
            else {
                while (!st.empty() and st.top().first >= arr[i])
                    st.pop();

                cout << (st.empty()? 0 : st.top().second) << " ";
            }
            st.push({arr[i], i + 1});
        }
    }

};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* SOL = new Solution();
    
    SOL->SOL_01();
    
    delete SOL;
    return 0;
}
