#include <iostream>

using namespace std;

void solve() {
    int a, b, c, max{0};
    cin >> a >> b >> c;
    int arr[] = { a + b + c, (a + b) * c, a * (b + c), a * b * c };
    for (int i = 0; i < 4; i++)
        if (arr[i] >= max)
            max = arr[i];
    cout << max;
}

int main() {
    solve();
    return 0;
}
