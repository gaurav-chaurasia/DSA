// Given a set of digits(A) in sorted order,
// find how many numbers of length B are possible
// whose value is less than number C.
// repetation of digit not allowd

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> getDigit(int num) {
    vector<int> temp;
    while (num != 0) {
        temp.push_back(num % 10);
        num /= 10;
    }
    reverse(temp.begin(), temp.end());
    // sort(temp.begin(), temp.end());
    return temp;
}

int getMulti(int start, int end, int dif) {
    int product = 1;
    for (int i = start; i < end; i++) {
        product = product * (dif);
    }
    return product;
}

int getCount(int value, vector<int> vec, int len) {
    int j = len;
    for (int i = 0; i < len; i++) {
        if (vec[i] >= value)
            return i;
    }
    return j;
}

int solve(vector<int> &a, int b, int c) {
    vector<int> d = getDigit(c);
    int n = a.size(), 
        m = d.size(),
        sum = 0;
    if (c == 0 and a[0] == 0 and b == 1) return 1;
    if (a.empty()) return 0;
    if (b > getDigit(c).size()) return 0;
    if (b > a.size()) return 0;
    if (b == 1 and a.size() == 1 and a[0] < c) return 1;
    if (b == 1) {
        return getCount(c, a, n);
    }
    // for (auto it: d) cout << it << " ";
    if (a[0] == 0) {
        int minCount = getCount(d[0], a, n);
        sum = (minCount-1) * getMulti(1, m, n) + sum;
        for (int i = 1; i < m-1; i++) {
            int minCount = getCount(d[i], a, n);
            sum = minCount*getMulti(i+1, m, n) + sum;
        }
        sum = sum + getCount(d[m-1], a, n);
    } else {
        for (int i = 0; i < m-1; i++) {
            int minCount = getCount(d[i], a, n);
            sum = minCount*getMulti(i+1, m, n) + sum;
        }
        sum = sum + getCount(d[m-1], a, n);
    }
    return sum;
}

int main() {
    // int t{0}, b = 50074;
    // cin >> t;
    // while (t--){
    vector<int> a{0, 1, 2, 5};
    int b = 2, c = 21;
    cout << solve(a, b, c);
    // }
    return 0;
}