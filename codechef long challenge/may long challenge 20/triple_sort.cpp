#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
// #include <string>
#include <map>
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

// int find_index(int val, int temp[], int arr_len)
// {
//     rep(i, 0, arr_len - 1)
//     {
//         if (val == temp[i])
//             return i;
//     }
// }

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    map<int, int> p, p1, mp;
    rep(i, 0, n - 1)
    {
        cin >> p[i];
        arr[i] = p[i];
        mp[i] = p[i];
        p1[p[i]] = i;
    }
    sort(arr, arr + n);
    // unsorted array p[n]
    // sorted array   arr[n]
    int i1 = 0, i2 = 0, i3 = 0, i = 0, m = 0, temp = 0;
    vector<ppi> v{};
    while (i < n)
    {
        // if (arr[i] == p[i]) {
        //     continue;
        // }
        if (arr[i] != p[i])
        {
            i1 = i;
            i2 = *lower_bound(arr , arr+n, p[i]);
            // i2 = find_index(p[i], arr, n);
            // i3 = find_index(arr[i], p, n);
            i3 = p1.find(arr[i])->second;
            cout << i1 << "--" << i2 << "--" << i3 << endl;
            if (i2 == i3)
            {
                // int j = i+1;
                // while (j < n)
                // {
                //     if (arr[j] != p[j] && j != i1 && j != i3)
                //     {
                //         i2 = j;
                //         break;
                //     }
                //     j++;
                // }
                i2 = mp.begin()->first;
            }
            if (i2 == i3) {
                m = k + 1;
                break;
            }
            m++;
            temp = p[i1];
            p[i1] = p[i3];
            p[i3] = p[i2];
            p[i2] = temp;
            if (p[i1] == arr[i1] && p[i2] == arr[i2]) {
                mp.erase(i1);
                mp.erase(i2);
            }
            ppi p{i1 + 1, {i2 + 1, i3 + 1}};
            v.pb(p);
        }
        i++;
    }

    // rep (i, 0, n-1) { //for printing sorted array
    //     cout << p[i];
    // }cout << endl;
    // for (auto it = p.begin(); it != p.end(); it++){
    //     cout << it->second << " ";
    // }cout << endl;

    if (m <= k)
    {
        cout << m << endl;
        for (auto it : v)
            cout << it.first
                 << " "
                 << it.second.first
                 << " "
                 << it.second.second
                 << endl;
    }
    else
        cout << -1 << endl;
}

int main()
{
    int t{0};
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
