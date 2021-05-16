#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n; cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    sort(arr, arr+n);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans + 1 < arr[i])
            break;

        ans += arr[i];
    }

    cout << ans + 1 << endl;
    return 0;
}
