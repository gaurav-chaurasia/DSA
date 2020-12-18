#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    int n{0}, temp, count = 0;
    cin >> n;
    temp = 5;

    while (ceil(n / temp) > 0)
    {
        count = count + ceil(n / temp);
        temp = temp * 5;
    }
    cout << count << " ";
}

int main()
{

    int t{0}; // taking input for number of test case
    cin >> t;

    while (t--)
    {
        solve();
    }
    cout << endl;
    return 0;
}