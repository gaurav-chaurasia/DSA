#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

/**
 * in such case on median gives the optimum result
*/
int main() {
    int n; cin >> n;
    vector<int> length(n);
    for(int i = 0; i < n; i++) 
        cin >> length[i];

    sort(length.begin(), length.end());

    ll cost = 0;
    ll avg = length[n/2];

    for (int i = 0; i < n; i++)
        cost += abs(length[i] - avg);

    cout << cost << endl; 
    return 0;
}
