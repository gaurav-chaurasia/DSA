#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
// #include <string>
// #include <map>
// #include <set>

#define rep(i, a, b)  for (int i = a; i <= b; i++)
#define isEqual(a, b) a == b ? 1 : 0
#define MAX(a, b)     a > b ? a : b
#define MIN(a, b)     a < b ? a : b
#define SQ(a)         (a) * (a)
#define vi            vector<int>
#define vc            vector<char>
#define vs            vector<string>
#define pb            push_back
#define pi            pair<int, int>
#define ppi           pair<int, pi>
#define pll           pair<long long, long long>
#define ppll          pair<long long, pll>

typedef long long ll;

using namespace std;

int count_binary_digit(ll a)
{
    int count = 0;
    while (a > 0)
    {
        a /= 2;
        count++;
    }
    return count;
}

void get_binary(int arr[], ll num)
{
    int i = 64;
    while (num > 0)
    {
        arr[i] = num % 2;
        num /= 2;
        i--;
    }
}

ll get_decimal(int arr[])
{
    int i = 63, temp = 2;
    ll sum = arr[64] * 1;
    while (i >= 0)
    {
        sum = sum + (ll)temp * arr[i];
        i--;
        temp *= 2;
    }
    return sum;
}

ll solve()
{
    int xrr[65]{}, yrr[65]{}, lrr[65]{}, rrr[65]{}, zrr[65]{};
    ll x, y, l, r;
    cin >> x >> y >> l >> r;
    if (l == r)
        return l;
    if ((x | y) <= r && (x | y) >= l)
        return x | y;
    if ((l - r) == 1)
    {
        if ((x & r) * (y & r) > (x & l) * (y & l))
            return r;
        else
            return l;
    }

    int num_digit[5]{};
    num_digit[0] = count_binary_digit(x);
    num_digit[1] = count_binary_digit(y);
    num_digit[2] = count_binary_digit(l);
    num_digit[3] = count_binary_digit(r);
    num_digit[4] = count_binary_digit(x | y);
    // cout << endl << num_digit[0] << " count " << num_digit[1] << endl;

    get_binary(xrr, x);
    get_binary(yrr, y);
    get_binary(lrr, l);
    get_binary(rrr, r);
    get_binary(zrr, x | y);

    // rep (i, 0, 39) {
    //     cout << xrr[i];
    // }
    // cout << endl;
    // rep (i, 0, 39) {
    //     cout << yrr[i];
    // }
    // cout << endl;

    // rep(i, 0, 39)
    // {
    //     cout << zrr[i];
    // }
    if ((x | y) > r)
    {
        rep(i, 0, 65 - num_digit[3])
        {
            zrr[i] = 0;
        }
        if (get_decimal(zrr) > l)
            return get_decimal(zrr);
        // else
        // {
        // }
    }
    if ((x | y) < l)
    {
        if (((x | y) | l) < r)
            return (x | y) | l;
        // else
        // {
        // }
    }
}

int main()
{
    int t{0};
    cin >> t;
    while (t--)
    {
        ll ans = solve();
        cout << ans << endl;
    }
    return 0;
}
