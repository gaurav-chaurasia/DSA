// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define deb(x)         cout << #x << " " << x << endl;
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

typedef long long ll;
typedef unsigned long long ull;

int solve() {
    int n, current_count = 1;
    cin >> n;
    vector <int> g(n);
    for (int &el : g)
        cin >> el;
    sort (all(g));
    for (int i = n-1; i >= 0; --i) {
        if (g[i] <= i+1)
            return i + current_count + 1;
    }
    return current_count;
}
 
int main() {
    int t{0};
    cin >> t;
    while (--t){
       cout << solve() << endl;
    }   
    return 0;
}
