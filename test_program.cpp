#include <bits/stdc++.h>
 
using namespace std;

#define setbits(x)      __builtin_popcountll(x) // gives number of set bits in a number
#define zrobits(x)      __builtin_ctzll(x) // gives number of leading zeros 
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x // set y precision after decimal 
#define mk(arr,n,type)  type *arr=new type[n]; // makes arr of size n 
#define EPS   			1e-9 // almost zero 
#define PI    			3.1415926535897932384626433832795
#define w(x)            int x; cin>>x; while(x--)
#define mod             1000000007 // 1e9+7
 
typedef long long ll;
typedef unsigned long long ull;
 
void infacted(vector<int> speed, int cur, int time, vector<int> &meet, int &MIN, int &MAX) {
    int n = speed.size();
    int sum = 0;
    for (auto it: meet)
        if (it == 1) sum++;
    MAX = max(MAX, sum);
    
    if (cur == n-1) return;
    
    for (int i = cur; i < n-1; i++) {
        meet[i] = 1;
        for (int j = i+1; j < n; j++) {
            if (speed[i] == speed[j]) continue;
            int t = (i - j) / (speed[j] - speed[i]);// calculating time for meeting i and j 
            if (t >= time) {
                infacted(speed, j, t, meet, MIN, MAX);
            }
        }
        meet[i] = 0;
    }
} 
 
void solve() {
	// your code goes here!!!
    int n; cin >> n;
    int MIN = INT_MAX, MAX = INT_MIN;
    vector<int> speed(n);
    for (int i =0; i < n; i++) cin >> speed[i];

    // vector<vector<bool>> meet(n, vector<bool> (n, false));
    vector<int> meet(n, 0); // assuming every one is not infacted
    infacted(speed, 0, 0, meet, MIN, MAX);

    MAX == INT_MIN ? cout << 1 << endl : cout << MAX << endl;
}
 
int main() {
    w(t) {
       solve();
    }   
    return 0;
}
