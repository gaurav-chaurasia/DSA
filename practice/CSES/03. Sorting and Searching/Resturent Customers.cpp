#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;


/**
 * In this problem we are asked to find out max customers
 * in resturent
 **/
int main() {
    int n, a, b; cin >> n;
    vector<pair<int, bool>> ts;

    /**
     * taking interval input in vector
     * when customer enters then we consider @second true
     * when customer leaves then we consider @second false
    */
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ts.push_back(make_pair(a, true));
        ts.push_back(make_pair(b, false));
    }

    sort(ts.begin(), ts.end());

    int MAX = 0, ans = 0;     
    for (int i = 0; i < ts.size(); i++) {
        if (ts[i].second) {
            ans++;
            MAX = max(MAX, ans);
        } else {
            ans--;
        }
    }
    cout << MAX << endl;
    return 0;
}
