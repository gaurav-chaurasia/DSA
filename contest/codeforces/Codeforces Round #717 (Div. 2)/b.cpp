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
    int n;
    cin >> n;
    int a[n];
    int x = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x ^= a[i];
    }

    if (x == 0)
        cout << "YES" << endl;
    else {
        // 5 1 4 5 -> 5 5 5
        // 5 5 5 5 5
        int k = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            k ^= a[i];
            if (k == x) {
                k = 0;
                count++;
            }
        }

        if (count >= 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    w(t){
       solve();
    }   
    return 0;
}
