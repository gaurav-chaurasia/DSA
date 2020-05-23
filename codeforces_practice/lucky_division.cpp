#include <iostream>
#include <string>

using namespace std;

int solve() {
    int arr[] = {4, 7, 47, 74, 444, 447, 474, 744, 774, 747, 477, 777},
        count = 0,
        n;
    cin >> n;
    for (int i = 0; i < 12; i++) {
        if (n % arr[i] == 0)
            count++;
    }
    if (count != 0)
        cout << "YES";
    else
        cout << "NO";
}

int main() {
    solve();
    return 0;
}
