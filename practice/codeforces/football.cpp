#include <iostream>
#include <string>

using namespace std;

int solve() {
    int count;
    string str;
    cin >> str;
    if ((str.find("0000000") != string::npos) || (str.find("1111111") != string::npos))
        cout << "YES";
    else
        cout << "NO";
}

int main() {
    solve();
    return 0;
}
