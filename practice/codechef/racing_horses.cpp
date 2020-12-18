#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    int i{0};
    cin >> i;
    long long arr[i], min = 1000000000;
    for (int j = 0; j < i; j++) {
        cin >> arr[j];
    }
    sort(arr, arr + i);

    for (int k = 0; k < i - 1; k++) {
        if (min >= abs(arr[k + 1] - arr[k])) {
            min = abs(arr[k + 1] - arr[k]);
        }
    }

    cout << min;
}

int main()
{
    int t{0};
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}