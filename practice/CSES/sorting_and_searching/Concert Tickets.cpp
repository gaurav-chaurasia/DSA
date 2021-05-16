#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;
int temp, res;

int main() {
    int i, n, m; cin >> n >> m;
    multiset<int, greater<int>> h;
    
    while (n--) {
        cin >> temp;
        h.insert(temp);
    }

    // for(auto it: h) DEB(it); 
    // cout << distance(h.begin(), h.lower_bound(6));
    // NL();

    // for(auto it: t) DEB(it); NL();
    
    while(m--) {
        cin >> temp;
        auto it = h.lower_bound(temp);

        if (it != h.end()) {
            res = *it;
            h.erase(it);
        } 
        else {
            res = -1;
        }
        cout << res << endl;
    }
    return 0;
}
