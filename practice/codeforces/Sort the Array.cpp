// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

 
using namespace std;

#define rep(i, j)          for(int i = 0; i < j; i++)
#define rrep(i, j)         for(int i = j-1; i >=0; i--)
#define all(cont)          cont.begin(), cont.end()
#define rall(cont)         cont.end(), cont.begin()
#define foreach(it, l)     for (auto it = l.begin(); it != l.end(); it++)
#define sq(a)              (a)*(a)
#define mp                 make_pair
#define pb                 push_back
#define INF                (int)1e9
#define EPS                1e-9
#define PI                 3.1415926535897932384626433832795
#define MOD                1000000007
 
typedef long long int          ll;
typedef unsigned long long int ull;
 
void solve() {
    int len, st = -1, en = -1;
    cin >> len;
    vector<int> a(len), a1(len);
    rep(i, len) { 
        cin >> a[i];
        a1[i] = a[i];
    }
    sort(all(a1));
    rep(i, len) {
        if (a[i] != a1[i]) {
            auto end = find(all(a), a1[i]);
            auto start = find(all(a), a[i]);
            st = distance(a.begin(), start);
            en = distance(a.begin(), end);
            reverse(start, ++end);
            break;
        }
    }
    rep (i, len) {
        if (a[i] != a1[i]) {
            cout << "no";
            return;
        }
    }
    if (st == -1 and en == -1)
        cout << "yes" << endl
             << 1 << " " << 1;
    else
        cout << "yes" << endl 
             << ++st << " " << ++en;
}
 
int main() {
    solve();
    return 0;
}
