#include <bits/stdc++.h>
 
using namespace std;

#define all(cont)      cont.begin(), cont.end()
#define rall(cont)     cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define sq(a)          (a)*(a)
#define mp             make_pair
#define pb             push_back
#define INF            (int)1e9
#define EPS            1e-9
#define PI             3.1415926535897932384626433832795
#define MOD            1000000007

typedef long long int ll;
typedef unsigned long long int ull;

ll nSum(ll n) {
    return (n * (n + 1)) / 2;
}

ll solve() {
    ll n, x, ans = 0;
    cin >> n >> x;
    vector<ll> a(n*2), b = {0}, c = {0};
    // b to store days till that day like if
    //  n = 3, a1 = 1, a2 = 4, a3 = 2
    // then in first month 1 day
    // till second month 1 + 4 >> 5 day 
    // means only when days till the more than x then come

    // and c is some sum of day till the month 

    for (int i = 0; i < n; i++) { 
        cin >> a[i];
        a[n+i] = a[i];
    }
    n *= 2;
    
    for (int i = 0; i < n; i++) b.pb(b.back() + a[i]);
    for (int i = 0; i < n; i++) c.pb(c.back() + nSum(a[i]));
    for (int i = 0; i < n; i++) {
        if (b[i+1] >= x) {
            ll  end = upper_bound(all(b), b[i+1] - x) - b.begin();
            ll day = b[i+1] - b[end];
            ll extra = x - day;
            ll cur_ans = c[i+1] - c[end];
            cur_ans += nSum(a[end - 1]);
            cur_ans -= nSum(a[end - 1] - extra);
            ans = max(ans, cur_ans);
        }
    }
    return ans;
}
 
int main() {
    cout << solve();
    return 0;
}
