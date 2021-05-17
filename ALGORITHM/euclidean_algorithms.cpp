#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin >> x; while (x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second

class Solution
{

public:
    // euclidean_algorithms for GCD
    int GCD(int a, int b) {
        if (a == 0)
            return b;
        
        return gcd(b % a, a);
    }

    // Extended Euclidean Algorithms for GCD
    int Extended_GCD(int a, int b, int *x, int *y) {
        // Base Case
        if (a == 0) {
            *x = 0;
            *y = 1;
            return b;
        }

        int x1, y1; // To store results of recursive call
        int gcd = Extended_GCD(b % a, a, &x1, &y1);

        // Update x and y using results of
        // recursive call
        *x = y1 - (b / a) * x1;
        *y = x1;

        return gcd;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    DEB(SOL->GCD());

    delete SOL;
    return 0;
}
