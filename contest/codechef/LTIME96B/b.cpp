#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

void change(string &str, int i) {
    str[i] = (str[i] == '0') ? '1' : '0'; 
}

void solve() {
    // your code goes here!!!
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    int total_dist = 0;
    if (n > 1){
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == str[i - 1]) {
                total_dist += 2;
            }
            else {
                total_dist += 1;
            }
        }
    }
    while (k--) {
        int temp;
        cin >> temp;
        int idx = temp - 1;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        if (idx - 1 >= 0) {
            if (str[idx] == str[idx - 1]) {
                total_dist -= 1;
            }
            else {
                total_dist += 1;
            }
        }
        if (idx + 1 < n) {
            if (str[idx] == str[idx + 1]) {
                total_dist -= 1;
            }
            else {
                total_dist += 1;
            }
        }
        change(str, idx);
        cout << total_dist << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    w(t) {
       solve();
    }
    
    return 0;
}
