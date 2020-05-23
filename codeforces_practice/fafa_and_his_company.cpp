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

#define rep(i, a, b)  for (int i = a; i <= b; i++)
#define w             while
#define d             do
#define isEqual(a, b) a == b ? 1 : 0
#define MIN(a, b)     a < b ? a : b
#define MAX(a, b)     a > b ? a : b
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

void solve()
{
    int n;
    cin >> n;
    int i = 1, count = 0;
    w (i <= (n / 2)) {
        if ((n-i) % i == 0) count++;
        i++;
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
