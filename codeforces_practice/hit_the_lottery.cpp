// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <bitset>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define isEqual(a, b) a == b ? 1 : 0
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

int main() {
    ll n, i = 0, j = 0, count = 0;
    cin >> n;
    int denomination[] = {100, 20, 10, 5, 1};
    while (n > 0) {
        if (n-denomination[i] >= 0) {
            n -= denomination[i];
            count++;
        } else i++;
    }
    cout << count;
    return 0;
}
