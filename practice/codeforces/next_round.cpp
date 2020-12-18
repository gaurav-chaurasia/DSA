#include <iostream>
#include <string>

using namespace std;

int n, k, i, j, a[51];
void solve() {
    cin >> n >> k;
    while (n > i)
        cin >> a[i++];
    while (a[j] && a[j] >= a[k - 1])
        ++j;
    cout << j;
}

int main() {
    solve();
    return 0;
}