#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

void print_vector(vector<int> a) {
    for (auto it: a) {
        DEB(it);
    }
    NL();
}

void find_winner(vector<int> a, vector<int> b, ll asum, ll bsum) {
    int result = 0, n = a.size(), m = b.size();
    if (asum > bsum) {
        cout << result << endl;
        return;
    }
    for (int i = 0, j = m-1; i < n && j >= 0; i++, j--) {
        if (asum > bsum || b[j] <= a[i]) {
            break;
        }
        if (b[j] > a[i]) {
            asum += b[j];
            asum -= a[i];
            bsum -= b[j];
            bsum += a[i];
            swap(a[i], b[j]);
            result++;
        }
    }
    asum > bsum ? result = result : result = -1;  
    cout << result << endl;
}

void solve() {
    int n, m; cin >> n >> m;
    ll asum = 0, bsum = 0;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        asum += a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        bsum += b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    find_winner(a, b, asum, bsum);
}
 
int main() {
    int t; cin >> t;
    while(t--){
       solve();
    }   
    return 0;
}
