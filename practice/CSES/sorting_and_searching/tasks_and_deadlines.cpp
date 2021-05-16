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
    static bool compare(pi a, pi b) {
        if (a.f != b.f)
            return a.f < b.f;
        
        return a.s < b.s;
    }

    void SOL_01() {
        int n; cin >> n;
        vector<pi> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i].f >> arr[i].s;
        
        sort(all(arr), compare);
        
        ll current_time = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            current_time += arr[i].f;
            ans += arr[i].s - current_time;
        }
        cout << ans << endl;
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
