#include <bits/stdc++.h>
using namespace std;
 
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;
 
int main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> vec;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        vec.push_back(make_pair(a, i));
    }

    sort(vec.begin(), vec.end());

    for (int i = 0, j = n-1; i < j;) {
        if (vec[i].first + vec[j].first == x) {
            cout << ++vec[i].second << " " << ++vec[j].second << endl;
            return 0;
        } 
        else {
            vec[i].first + vec[j].first > x ? --j : ++i;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}