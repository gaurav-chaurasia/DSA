#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t{0}, count = 0;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if (str.at(0) == '-' || str.at(2) == '-')
            count--;
        if (str.at(0) == '+' || str.at(2) == '+')
            count++;
    }
    cout << count;
    return 0;
}
