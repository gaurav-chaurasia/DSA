#include <iostream>

using namespace std;

void solve() {
    unsigned long long n, m, a, count = 0;
    cin >> n >> m >> a;

    if ((n % a) == 0 && ((m % a) == 0))
    {
        count = (n / a) * (m / a);
    }
    if ((n % a) != 0 || ((m % a) != 0))
    {
        if (n % a == 0)
        {
            count = (n / a) * ((m / a) + 1);
        }
        else
        {
            count = ((n / a) + 1) * (m / a);
        }
    }
    if ((n % a) != 0 && ((m % a) != 0))
    {
        count = ((n / a) + 1) * ((m / a) + 1);
    }

    cout << count << endl;
}

int main() {
    solve();
    return 0;
}
// 2       8
//   [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
// 8 [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
//   4 * (4 / 2)

// 2       7
//   [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
// 4 [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
//   4 * (4 / 2)

// 2       8
//   [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
// 8 [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
//   [][][][][][][][]
//   4 * (4 / 2)