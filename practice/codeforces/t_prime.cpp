// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <bitset>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>

#define rep(i, a, b)  for (int i = a; i <= b; i++)
#define w             while
#define d             do
#define isEqual(a, b) a == b ? 1 : 0
#define SQ(a)         (a) * (a)
#define vi            vector<int>
#define vll           vector<long long>
#define vc            vector<char>
#define vs            vector<string>
#define pb            push_back
#define pi            pair<int, int>
#define ppi           pair<int, pi>
#define pll           pair<long long, long long>
#define ppll          pair<long long, pll>

#define MAX 10000000
int primes[MAX];
typedef long long ll;

using namespace std;

void getPrimes() { // seive to get primes till MAX;
    rep(i, 0, MAX - 1) {
        primes[i] = 1;
    }
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i <= sqrt(MAX); i++) {
        for (int j = 2; i*j <= MAX; j++) {
            primes[i*j] = 0;
        }
    }
}

int main() {
    getPrimes();
    int n;
    cin >> n;
    vll input;

    rep(i, 0, n - 1)
    {
        ll temp{0};
        cin >> temp;
        ll index = sqrt(temp);
        if (SQ(index) != temp)
        {
            cout << "NO" << endl;
            continue;
        }
        if (primes[index] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    // cout << "\n\n";
    return 0;
}
