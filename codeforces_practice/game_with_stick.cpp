#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n >= m) {
        if (m % 2 == 0)
            cout << "Malvika";
        else
            cout << "Akshat";
    } else {
        if (n % 2 == 0)
            cout << "Malvika";
        else
            cout << "Akshat";
    }
    return 0;
}