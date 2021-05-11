#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    void SOL_01() {
        // taking n and x as 
        // n length 
        // x number of light 
        int n, x;
        cin >> n >> x;

        set<int> lights;
        multiset<int> dist;
        lights.insert(0);
        lights.insert(n);
        dist.insert(n);

        for (int i = 0; i < x; i++) {
            int p; cin >> p;
            auto it1 = lights.upper_bound(p), it2 = it1; --it2;
            
            dist.erase(dist.find(*it1 - *it2));
            dist.insert(p - *it2);
            dist.insert(*it1 - p);
            lights.insert(p);

            auto ans = dist.end(); --ans;
            cout << *ans << " ";
        }
    }

};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution* SOL = new Solution();    
    SOL->SOL_01();
    
    delete SOL;
    return 0;
}
