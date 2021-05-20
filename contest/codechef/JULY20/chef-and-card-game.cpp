#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

ll get_marks(ll a) {
    ll sum =0;
    while (a > 0) {
        sum += a%10;
        a /= 10;
    }
    return sum;
}

void solve() {
    ll n, chef =0, morty =0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, a_marks =0, b_marks =0;
        cin >> a >> b;
        a_marks = get_marks(a);        
        b_marks = get_marks(b);

        if (a_marks > b_marks)
            chef++;
        else if (a_marks < b_marks)
            morty++;
        else {
            chef++;
            morty++;
        }
    }
    if (chef > morty)
        cout << 0 << " " << chef << endl;
    else if (morty > chef)
        cout << 1 << " " << morty << endl;
    else
        cout << 2 << " " << chef << endl;
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       solve();
    }   
    return 0;
}
