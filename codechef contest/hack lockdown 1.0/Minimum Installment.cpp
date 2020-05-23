#include <bits/stdc++.h>
 
using namespace std;

#define MEM(a, b)          memset(a, (b), sizeof(a))
#define _for(i, j, k, in)  for (int i = j; i < k; i += in)
#define _rfor(i, j, k, in) for (int i = j; i >= k; i -= in)
#define rep(i, j)          _for(i, 0, j, 1)
#define rrep(i, j)         _rfor(i, j, 0, 1)
#define all(cont)          cont.begin(), cont.end()
#define rall(cont)         cont.end(), cont.begin()
#define foreach(it, l)     for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C)        assert(B <= A && A <= C)
#define sq(a)              (a)*(a)
#define mp                 make_pair
#define pb                 push_back
#define f                  first
#define s                  second
#define INF                (int)1e9
#define EPS                1e-9
#define PI                 3.1415926535897932384626433832795
#define MOD                1000000007
 
// const double pi = acos(-1.0);
 
typedef pair<int, int>         pi;
typedef pair< int, pi>         ppi;
typedef vector<int>            vi;
typedef vector<string>         vs;
typedef vector<vi>             vvi;
typedef map<int, int>          mapi;
typedef set<int>               seti;
typedef multimap<int, int>     mmapi;    
typedef multiset<int>          mseti;
typedef long int               int32;
typedef unsigned long int      uint32;
typedef long long int          int64;
typedef unsigned long long int uint64;
 
void solve() {
    int32 n, m;
    cin >> n >> m;
    int32 a[n][3];
    rep(i,n) {
        a[i][0] = 0;
        a[i][1] = 0;
        a[i][2] = 0;
    }
    rep(i, m) {
        int32 a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a[a1-1][0] += a3;
        a[a2-1][1] += a3;
    }
    int32 sum = 0;
    rep(i, n) {
        a[i][2] = abs(a[i][1] - a[i][0]);
    }
    rep(i, n) { sum += a[i][2]; }
    cout << sum / 2;
}
 
int main() {
    solve();
    return 0;
}
