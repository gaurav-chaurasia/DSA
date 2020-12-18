#include <bits/stdc++.h>

using namespace std;
 
#define SCD(t)            scanf("%d", &t)
#define SCLD(t)           scanf("%ld", &t)
#define SCLLD(t)          scanf("%lld", &t)
#define SCC(t)            scanf("%c", &t)
#define SCS(t)            scanf("%s", t)
#define SCF(t)            scanf("%f", &t)
#define SCLF(t)           scanf("%lf", &t)
#define MEM(a, b)         memset(a, (b), sizeof(a))
#define FOR(i, j, k, in)  for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j)         FOR(i, 0, j, 1)
#define RREP(i, j)        RFOR(i, j, 0, 1)
#define all(cont)         cont.begin(), cont.end()
#define rall(cont)        cont.end(), cont.begin()
#define FOREACH(it, l)    for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C)       assert(B <= A && A <= C)
#define sq(a)             (a)*(a)
#define mp                make_pair
#define pb                push_back
#define INF               (int)1e9
#define EPS               1e-9
#define PI                3.1415926535897932384626433832795
#define MOD               1000000007
#define read(type)        readInt<type>()
 
// const double pi = acos(-1.0);
 
typedef pair<int, int>         pi;
typedef pair< int, pi>         ppi;
typedef vector<int>            vi;
typedef vector<string>         vs;
typedef vector<vi>             vvi;
typedef map<int, int>          mapi;
typedef set<int>               seti;
typedef multiset<int>          mseti;
typedef long int               int32;
typedef unsigned long int      uint32;
typedef long long int          int64;
typedef unsigned long long int uint64;


void solve() {
    int32 n, k;
    cin >> n >> k;
    vector<int64> a;
    int64 sum = (int64)(n*(n+1))/2, result = 0;
    int32 j = 1, N = floor(n / k);
    sum = sum - (int64)(k * ((N * (N + 1)) / 2));
    for (int64 i = k; i <= n; j++, i = k * j) {
        while (i % k == 0) {
            i /= k;
        }
        // a.pb(i);
        result += i;
    }
    // for (auto it : a) {
    //     result += it;
    // }
    cout << (sum+result) << endl;
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       solve();
    }   
    return 0;
}
