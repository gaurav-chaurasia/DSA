#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
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
    void largest_subarray_with_k_unique_char(string str, int k) {
        // your code goes here!!!
        int n = str.size();
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        while (j < n) {
            // adding element in map
            mp[str[j]]++;

            if (mp.size() < k) {
                j++;
            }
            // if condition is 
            else if (mp.size() == k){
                ans = max(ans, j - i + 1);
                j++;
            }
            else {
                while (mp.size() > k) {
                    if (mp[str[i]] > 1) {
                        mp[str[i]]--;
                    }
                    else {
                        mp.erase(str[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        DEB(ans);
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    string str = "aabacbebebe";
    SOL->largest_subarray_with_k_unique_char(str, 3);
    
    delete SOL;
    return 0;
}
