#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pi = pair<int, int>;
using ppi = pair<int, pi>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second

const int MAX_CHAR = 256;
const int MOD = 1000000007;

void solve()
{
    ll n, a, b;
    ll area = LONG_MAX;

    cin >> n;

    std::vector<pair<ll, ll>> x;
    std::vector<pair<ll, ll>> y;
    multiset<ll> X;
    multiset<ll> Y;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        x.push_back({a, b});
        y.push_back({b, a});
        X.insert(a);
        Y.insert(b);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll hmax = 0, hmin = LONG_MAX, h1, h2;
    ll wmax = 0, wmin = LONG_MAX, w1, w2;

    for (int i = 0; i < n - 1; i++)
    {
        hmax = max(x[i].second, hmax);
        hmin = min(x[i].second, hmin);

        h1 = hmax - hmin;

        auto it = Y.find(x[i].second);
        Y.erase(it);

        h2 = *(Y.rbegin()) - *(Y.begin());
        ll newarea = h1 * (x[i].first - x[0].first) + h2 * (x[n - 1].first - x[i + 1].first);

        area = min(area, newarea);
    }

    for (int i = 0; i < n - 1; i++)
    {
        wmax = max(y[i].second, wmax);
        wmin = min(y[i].second, wmin);

        w1 = wmax - wmin;
        auto it = X.find(y[i].second);
        X.erase(it);
        w2 = *(X.rbegin()) - *(X.begin());

        ll newarea = w1 * (y[i].first - y[0].first) + w2 * (y[n - 1].first - y[i + 1].first);
        area = min(area, newarea);
    }

    ll ans;
    if (n == 1)
        ans = 0;
    else
        ans = area;

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}