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
    void count_accurences_of_anagram(string str, string pattern) {
        int n = str.size();
        int k = pattern.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < k; i++)
        
        int i = 0, j = 0;
        while (j < str.size()) {
            
        }
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    string str = "aabaabaa";
    strign pat = "abaa";
    SOL->count_accurences_of_anagram(str, pat);
    
    delete SOL;
    return 0;
}
