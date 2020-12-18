#include <iostream>

using namespace std;

int solve()
{
    int n, m, clicks = 0; // n num on display , m wanted num
    // can perform **two times** or **one minus**
    cin >> n >> m;

    if (n < m)
    {
        // while (n * 2 <= m)
        // {
        //     n = n * 2;
        //     clicks++;
        // }
        // if (((2 * n - m) > (n - m / 2) && n != m))
        // {
        //     while (n != m / 2)
        //     {
        //         n--;
        //         clicks++;
        //     }
        //     return ++clicks;
        // }
        // else if (n == m)
        // {
        //     return clicks;
        // }
        // else
        // {
        //     n = 2 * n;
        //     while (n != m)
        //     {
        //         n--;
        //         clicks++;
        //     }
        //     return ++clicks;
        // }
        while (n < m) {
            if (m % 2 == 0)
                m = m / 2;
            else
                m++;
            clicks++;
        }
        return clicks + n - m;
    }
    else if (n == m)
    {
        return clicks = 0;
    }
    else
    {
        // while (n != m) {
        //     n--;
        //     clicks++;
        // }
        // return clicks;
        return n - m;
    }
}

int main()
{
    int clicks{0};
    clicks = solve();
    cout << clicks;
    return 0;
}