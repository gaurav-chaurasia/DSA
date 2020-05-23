#include <iostream>

using namespace std;

int solve()
{
    int n, t;
    cin >> n >> t;
    string str;
    cin >> str;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (str.at(j) == 'B' && str.at(j + 1) == 'G')
            {
                char temp = str.at(j);
                str.at(j) = str.at(j + 1);
                str.at(j + 1) = temp;
                j++;
            }
            else
                continue;
        }
    }
    cout << str;
}

int main() {
    solve();
    return 0;
}
