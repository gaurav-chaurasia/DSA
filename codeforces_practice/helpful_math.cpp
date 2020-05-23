#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int solve() {
    string str;
    cin >> str;
    if (str.length() > 2) {
        int arr_len = (str.length() / 2) + 1;
        char arr[arr_len];
        for (int i = 0, j = 0; i < str.length(); i += 2, j++)
            arr[j] = str.at(i);

        sort(arr, arr + arr_len);

        for (int i = 0; i < arr_len; i++) {
            if (i == arr_len - 1)
                cout << arr[i];
            else
                cout << arr[i] << '+';
        }
    }
    else
        cout << str;
}

int main() {
    solve();
    return 0;
}
