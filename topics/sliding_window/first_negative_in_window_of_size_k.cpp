#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

class Solution {

public:
    void first_negative_in_window_of_size_k(int n, vector<int> arr, int k) {
        queue<int> q;
        int j = 0, i = 0;

        while (j < arr.size()) {
            if (arr[j] < 0)
                q.push(arr[j]);
            
            if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {
                if (q.empty()) {
                    DEB(0);
                }
                else {
                    DEB(q.front());

                    if (q.front() == arr[i])
                        q.pop();
                    
                }
                i++;
                j++;
            }
        }
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    SOL->first_negative_in_window_of_size_k(arr.size(), arr, 3);
    
    delete SOL;
    return 0;
}
