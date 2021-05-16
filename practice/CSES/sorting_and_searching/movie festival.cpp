#include <bits/stdc++.h>
using namespace std;
 
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;
 
int main() {
    int n, a, b; cin >> n;
    vector<pair<int, int>> ts;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        /**
         * storing leaving time first and then comming time 
         * so that it will be easy to sort about leaving time 
         * we have to check and select those movies which ends early
        */
        ts.push_back(make_pair(b, a));
    }

    sort(ts.begin(), ts.end());

    int count = 1;
    int prev_movie = ts[0].first;
    for (int i = 1; i < n; i++) {
        if (prev_movie <= ts[i].second) {
            count++;
            prev_movie = ts[i].first;
        }
    } 
 
    cout << count << endl;
    return 0;
}