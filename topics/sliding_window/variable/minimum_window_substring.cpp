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
    void minimum_window_substring(string s, string t) {
        // your code goes here!!!
        int n = s.size();
        unordered_map<char, int> mp;
        
        for (char i: t) 
            mp[i]++;

        int count = mp.size();
        int i = 0, j = 0;
        int ans = INT_MAX;
        while (j < n) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--;
                }
            }

            if (count > 0) {
                j++;
            }
            else if (count == 0) {
                while (count == 0) {
                    ans = min(ans, j - i + 1);
                    
                    // optimizing ans
                    if (mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++;
                        if (mp[s[i]] == 1) {
                            count++;
                        }
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
    
    SOL->minimum_window_substring("TOTMTA", "TTA");
    
    delete SOL;
    return 0;
}
