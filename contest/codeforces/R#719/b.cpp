#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count_same_digit(ll L, ll R)
{
    ll tmp = 0, ans = 0;

    ll n = log10(R) + 1;

    for (ll i = 0; i < n; i++)
    {
        tmp = tmp * 10 + 1;

        for (ll j = 1; j <= 9; j++)
        {

            if (L <= (tmp * j) && (tmp * j) <= R)
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ll t; cin >> t;
    while (t--) {
        ll L = 1, R;
        cin >> R;
        cout << count_same_digit(L, R) << endl;
    }
    return 0;
}