#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using ppi = pair<int, pi>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

class Solution {

public:
    void removal_game() {

    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    SOL->removal_game(nums, );
    
    delete SOL;
    return 0;
}
