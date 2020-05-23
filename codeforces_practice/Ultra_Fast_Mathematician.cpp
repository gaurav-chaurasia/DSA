#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
// #include <string>
#include <map>
// #include <set>

#define rep(i, a, b)  for(int i=a;i<=b;i++) 
#define isEqual(a, b) a == b ? 1 : 0 
#define MAX(a, b)     a > b ? a : b
#define MIN(a, b)     a < b ? a : b
#define SQ(a)         (a)*(a)
#define vi            vector<int> 
#define vc            vector<char> 
#define vs            vector<string>
#define pb            push_back
#define pi            pair<int, int>
#define ppi           pair<int, pi>
#define pll           pair<long long, long long>
#define ppll          pair<long long, pll>

typedef long long ll;

using namespace std;

int main () {
    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == str2[i])
            cout << 0;
        else
            cout << 1;
    }
}