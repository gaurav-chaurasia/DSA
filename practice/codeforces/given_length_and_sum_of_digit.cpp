#include <iostream>

using namespace std;

void print (int arr[], int arr_len) {
  for (int i = 0; i < arr_len; i++)
    cout << arr[i];
}

void solve()
{
    int m, s1, s2;
    cin >> m >> s1;

    // int min = 1, max = 9;
    // for (int i = 0; i < m - 1; i++)
    //     min = min * 10 ;
    // for (int i = 0; i < m - 1; i++)
    //     max = max * 10 + 9;
    // cout << min << " - " << max << endl;

    s2 = s1;
    if (s1 == 0)
    {
        if (m == 1)
            cout << "0 0";
        else
            cout << "-1 -1";
        return;
    }

    if (s1 > 9 * m) {
        cout << "-1 -1";
        return;
    }

    int num1[m], num2[m];
    // smallest possible number
    s1 = s1 - 1;
    for (int i = m - 1; i > 0; i--) {
        if (s1 > 9) {
            num1[i] = 9;
            s1 = s1 - 9;
        } else {
            num1[i] = s1;
            s1 = 0;
        }
    }
    num1[0] = s1 + 1;

    // biggest possible number

    for (int i = 0; i < m; i++) {
        if (s2 > 9) {
            num2[i] = 9;
            s2 = s2 - 9;
        } else {
            num2[i] = s2;
            s2 = 0;
        }
    }

    // printing smallest and biggest number

    print(num1, m);
    cout << " ";
    print(num2, m);
}

int main() {
    solve();
    return 0;
}
