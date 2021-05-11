/*
here trick is if the book with largest time is less them or equal to
the sum of time of all other book the wile first person reading last book
second person can read other book and then can swithc the books 
and will complete the reading in most optimal time 
which is sum (t1, t2, t3, ... , tn);

otherwise it will take 2* times the time taken by the largest book
*/ 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second

class Solution {

public:
    void SOL_01() {
        int n; cin >> n;
        vector<ll> arr(n);

        ll sum = 0, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];

            mx = max(mx, arr[i]);
            sum += arr[i];
        }

        cout << max(sum, 2*mx) << endl;
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
