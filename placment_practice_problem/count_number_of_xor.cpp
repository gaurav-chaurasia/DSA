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

const int MAX_CHAR = 256;
const int MOD = 1000000007;

int solve(vector<int> arr, int k) {
    int xr = 0;
    int n = arr.size();
    int cnt = 0;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        xr = xr ^ arr[i];

        if (xr == k) {
            cnt++;
        }

        // -------= y ----- k = xr
        // y ^ k = xr;
        // y = k ^ xr;
        // if i could find number of y prefix xr 
        int y = k ^ xr;
        if (mp.find(y) != mp.end()) {
            cnt += mp[y];
        }

        mp[xr]++;
    }

    return cnt;
}
 
int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    cout << solve(arr, 6) << endl;
    return 0;
}