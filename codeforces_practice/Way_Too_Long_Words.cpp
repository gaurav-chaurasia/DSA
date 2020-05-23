#include <iostream>
#include <string>

using namespace std;

void solve()
{
    string str;
    cin >> str;
    if (str.length() > 10)
    {
        int b = str.length() - 2;
        char a = str.at(0),
             c = str.at(str.length() - 1);
        cout << a << b << c;
    }
    else
    {
        cout << str;
    }
    cout << endl;
}

int main()
{
    int t{0};
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}