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
 
void solve() {
	// your code goes here!!!
    int count = 0;
    vector<bool> locker(101, false);// locker 
    for (int i = 1; i <= 101; i++) {
        for (int j = i; j < 101; j += i) {
            if (locker[j]) 
                locker[j] = false;
            else 
                locker[j] = true;
        }
    }
    int i = 0;
    for (auto it : locker) { 
        if (it) count++;

        cout << i++ << "-> "<< it<<endl;
    }
    cout << "Number of Open Lockers: " << count << endl;
}
 
int main() {
    w(t) {
       solve();
    }   
    return 0;
}
