/*
3 7 ==> 3 machines we have and 7 products we need
3 2 5 ==> these are the time taken by respective machines to make one product


in time 1 sec
machines [1] will make 0 product 
machines [2] will make 0 product  ===> total num of machines in 1 sec [0]
machines [3] will make 0 product 

in time 2 sec
machines [1] will make 0 product 
machines [2] will make 1 product  ===> total num of machines in 2 sec [1]
machines [3] will make 0 product 

in time 3 sec
machines [1] will make 1 product 
machines [2] will make 1 product  ===> total num of machines in 3 sec [2]
machines [3] will make 0 product 

in time 4 sec
machines [1] will make 1 product 
machines [2] will make 2 product  ===> total num of machines in 3 sec [3]
machines [3] will make 0 product 

in time 5 sec
machines [1] will make 1 product 
machines [2] will make 2 product  ===> total num of machines in 3 sec [4]
machines [3] will make 1 product 

in time 6 sec
machines [1] will make 2 product 
machines [2] will make 3 product  ===> total num of machines in 3 sec [6]
machines [3] will make 1 product 

in time 7 sec
machines [1] will make 2 product 
machines [2] will make 3 product  ===> total num of machines in 3 sec [6]
machines [3] will make 1 product 

in time 8 sec
machines [1] will make 2 product  {min time to make 7 product}{answer}
machines [2] will make 4 product  ===> total num of machines in 3 sec [7]
machines [3] will make 1 product 

in time 9 sec
machines [1] will make 3 product 
machines [2] will make 4 product  ===> total num of machines in 3 sec [8]
machines [3] will make 1 product 
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rsz resize


class Solution {

public:
    void SOL_01() {
        int n, t; 
        cin >> n >> t;
        
        vi arr(n);
        for (int i = 0; i < n; i++) 
            cin >> arr[i];

        ll lo = 0;
        ll hi = 1e18;
        ll ans = 0;

        while (lo <= hi) {
            ll mid = (lo + hi)/2;
            ll sum = 0;

            for (int i = 0; i < n; i++) {
                sum += (mid / arr[i]);

                if (sum >= t)
                    break;
            }
            if (sum >= t) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        cout << ans << endl;
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
