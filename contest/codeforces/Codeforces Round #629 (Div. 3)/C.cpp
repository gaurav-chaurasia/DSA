#include <bits/stdc++.h>
 
using namespace std;
 
#define w(x)   int x; cin>>x; while(x--)
#define MOD    1000000007 // 1e9+7
#define DEB(x) cout << #x << "=>" << x << endl;
 
typedef long long ll;
typedef unsigned long long ull;

 
void solve() {
    int n;
    string x;   
    cin >> n >> x;
    string a(n, '0');
    for (int i = 0; i < n; ++i) {
        if (x[i] == '1') {
            a[i] = '1';
            x[i] = '0';
            break;
        } else if (x[i] == '2'){
            a[i] = '1';
            x[i] = '1';
        }
    }
    cout << a << endl << x << endl;
}
 
int main() {
    w(t){
       solve();
    }
    return 0;
}
