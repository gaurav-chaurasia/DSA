#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

int sum_ap(int n, int a, int d) {
    return (int)n * (2 * a + (n - 1) * d)/2;
}
void solve() {
    int D, d, p, q;
    cin >> D >> d >> p >> q;
    ll sum = 0;
    int n = D / d;

    sum = d * sum_ap(n, p, q);
    sum += (D % d) * (p + n * q);
    cout << sum << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    w(t){
       solve();
    }   
    return 0;
}