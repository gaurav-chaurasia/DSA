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

void solve() {
    int n, k; 
    cin >> n >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int i = 0;
    int j = sz(arr) - 1;

    while (k > 0 && i < j) {
        if (arr[i] == 0) {
            i++;
            continue;
        }
        if (arr[i] > 0) {
            arr[i]--;
            arr[j]++;
        }
        k--;
    }

    for (int it: arr) {
        cout << it << " ";
    }
    cout << endl;
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    w(t){
       solve();
    }   
    return 0;
}
