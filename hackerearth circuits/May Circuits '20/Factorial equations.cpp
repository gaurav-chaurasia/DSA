// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map> // map and multimap
#include <set> // set and multiset
#include <unordered_map> // unordered_map and unordered_multimap
#include <unordered_set> // unordered_set and unordered_multiset
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define SCD(t)            scanf("%d", &t)
#define SCLD(t)           scanf("%ld", &t)
#define SCLLD(t)          scanf("%lld", &t)
#define SCC(t)            scanf("%c", &t)
#define SCS(t)            scanf("%s", t)
#define SCF(t)            scanf("%f", &t)
#define SCLF(t)           scanf("%lf", &t)
#define MEM(a, b)         memset(a, (b), sizeof(a))
#define FOR(i, j, k, in)  for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j)         FOR(i, 0, j, 1)
#define RREP(i, j)        RFOR(i, j, 0, 1)
#define all(cont)         cont.begin(), cont.end()
#define rall(cont)        cont.end(), cont.begin()
#define FOREACH(it, l)    for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C)       assert(B <= A && A <= C)
#define SQ(a)             (a)*(a)
#define mp                make_pair
#define pb                push_back
#define INF               (int)1e9
#define EPS               1e-9
#define PI                3.1415926535897932384626433832795
#define MOD               1000000007
#define read(type)        readInt<type>()

// const double pi = acos(-1.0);

typedef pair<int, int>         pi;
typedef pair< int, pi>         ppi;
typedef vector<int>            vi;
typedef vector<string>         vs;
typedef vector<vi>             vvi;
typedef map<int, int>          mapi;
typedef set<int>               seti;
typedef multiset<int>          mseti;
typedef long int               int32;
typedef unsigned long int      uint32;
typedef long long int          int64;
typedef unsigned long long int uint64;

int32 factorial(int32 a) {
    if (a == 1 || a == 0) return 1;
    else {
        return a * factorial(a-1);
    }
}

void solve() {
   int32 n, x;
   cin >> x >> n;
   if (n >= 5) {
       cout << 1;
       return;
   }
   int32 result = factorial(n) % 10;
   x = x % 10;
   result = pow(x, result);
   result = result % 10;
   cout << result;
//    cout << factorial(6) << endl;
//    cout << factorial(5) << endl;
//    cout << factorial(4) << endl;
}

int main() {
    // int t{0};
    // cin >> t;
    // while (t--){
       solve();
    // }   
    return 0;
}
