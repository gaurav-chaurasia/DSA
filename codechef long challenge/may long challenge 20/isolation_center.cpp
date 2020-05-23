#include <iostream>

typedef long long ll;
using namespace std;

int solve()
{
    int n, q;
    string str;
    cin >> n >> q >> str;
    ll c[q]{};
    for (int i = 0; i < q; i++)
        cin >> c[i];

    ll arr[26]{}, temp[26];
    for (int i = 0; i < n; i++)
    {
        ++arr[str.at(i) - 97];
    }
    // for (int i = 0; i < 26; i++)
    //     cout << arr[i] + 1;
    //     cout << endl;
    for (int i = 0; i < q; i++)
    {
        for (int k = 0; k < 26; k++)
            temp[k] = arr[k];

        for (int j = 0; j < 26; j++)
        {
            if (c[i] >= temp[j])
            {
                temp[j] = 0;
            }
            if (c[i] < temp[j])
            {
                temp[j] = temp[j] - c[i];
            }
        }
        // cout << temp[4];
        int result = 0;
        for (int l = 0; l < 26; l++)
            result += temp[l];

        cout << result << endl;
    }
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
