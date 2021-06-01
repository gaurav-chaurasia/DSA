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

int inf_matrix[1001][1001];
void pre_compute() {
    for (int i = 1; i <= 1000; i++) {
        inf_matrix[i][1] = i * (i + 1) / 2;
        for (int j = 2; j <= 1000; j++) {
            inf_matrix[i][j] = inf_matrix[i][j - 1] + (j - 1) + (i - 1);
        }
    }
}

void solve() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    ll sum = 0;
    for (int i = r1; i <= r2; i++)
        sum += inf_matrix[i][c1];
    
    for (int i = c1 + 1; i <= c2; i++)
        sum += inf_matrix[r2][i];

    cout << sum << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pre_compute();
    w(t){
       solve();
    }   
    return 0;
}
