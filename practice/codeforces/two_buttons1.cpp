#include <iostream>

using namespace std;

int min_steps(int m, int n) {
    if (n == m)
        return 0;
    int ans = 1 + min_steps(m + 1, n);
    if (m % 2 == 0) ans = min(ans, 1 + min_steps(m / 2, n));
}

int main () {
    int clicks = 0, n, m;
    cin >> n >> m;
    clicks = min_steps(m, n);
    cout << clicks << endl;
}