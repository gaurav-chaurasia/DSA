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
#define deb(x)      	cout << #x << "=>" << x << endl;// print variable and it's value x=>5
 
typedef long long ll;
typedef unsigned long long ull;
 
void solve() {
    int n, k;
    cin >> n >> k;
    int x = ceil((-1 + pow((1+8*k), 0.5)) / 2 );
    int firstIndex = n - x - 1;
    int secondIndex = n - k + (((x-1)*x)/2);
    for (int i = 0; i < n; i ++) {
        if (i == firstIndex || i == secondIndex) {
            cout << 'b';
        } else {
            cout << 'a';
        }
    } 
    cout << endl;
}
 
int main() {
    w(t){
       solve();
    }   
    return 0;
}