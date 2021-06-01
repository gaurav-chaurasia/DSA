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

const int N = 1e7 + 2;
vector<bool> prime(N, true);
vector<int> prefix_prime(N, 0);

void seive() {
    prime[0] = prime[1] = false;
    
    for (int i = 2; i * i < N; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }
}

void pre_compute() {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (prime[i])
            count++;
        
        prefix_prime[i] = count;
    }
}

void solve() {
    int n; cin >> n;
    if (n == 2 || n == 3) {
        cout << n - 1 << endl;
    }
    else {
        cout << prefix_prime[n] - prefix_prime[n / 2] + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    seive();
    pre_compute();

    w(t) {
       solve();
    }
    
    return 0;
}
