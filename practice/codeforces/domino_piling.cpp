#include <iostream>

using namespace std;

int solve()
{
    int m, n, count = 0;
    cin >> m >> n;

    if (m % 2 == 0 || n % 2 == 0)
    {
        if (m % 2 == 0)
            count = (m / 2) * n;
        else
            count = (n / 2) * m;
    }
    if (m % 2 != 0 && n % 2 != 0)
        count = (m / 2) * (n) + (n / 2);

    cout << count;
}

int main() {
    solve();
    return 0;
}
