// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <bitset>
#include <vector>
#include <string>
#include <map>
#include <set>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define isEqual(a, b) a == b ? 1 : 0
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
#define SQ(a) (a) * (a)
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define pb push_back
#define pi pair<int, int>
#define ppi pair<int, pi>
#define pll pair<long long, long long>
#define ppll pair<long long, pll>

typedef long long ll;

using namespace std;

void solve() {
    int n, m;
    vi a, b;
    cin >> n;
    rep(i, 0, n-1) {
        int temp;
        cin >> temp;
        a.pb(temp);
    }
    cin >> m;
    rep(i, 0, m - 1) {
        int temp;
        cin >> temp;
        b.pb(temp);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        int temp = a.at(i) - b.at(j);
        if (temp >= -1 and temp <= 1){
            count++;
            i++;
            j++;
        }
        if (temp < -1) j++;
        if (temp > 1) i++;
    }
    cout << count;
}

int main() {
    // int t{0};
    // cin >> t;
    // while (t--) {
        solve();
    // }
    return 0;
}
