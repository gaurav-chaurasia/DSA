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
#include <map> // map and (multimap = can have multiple value with same key)
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

#define MEM(a, b)          memset(a, (b), sizeof(a))
#define _for(i, j, k, in)  for (int i = j; i < k; i += in)
#define _rfor(i, j, k, in) for (int i = j; i >= k; i -= in)
#define rep(i, j)          FOR(i, 0, j, 1)
#define rrep(i, j)         RFOR(i, j, 0, 1)
#define all(cont)          cont.begin(), cont.end()
#define rall(cont)         cont.end(), cont.begin()
#define foreach(it, l)     for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C)        assert(B <= A && A <= C)
#define sq(a)              (a)*(a)
#define mp                 make_pair
#define pb                 push_back
#define f                  first
#define s                  second
#define INF                (int)1e9
#define EPS                1e-9
#define PI                 3.1415926535897932384626433832795
#define MOD                1000000007
 
// const double pi = acos(-1.0);
 
typedef pair<int, int>         pi;
typedef pair< int, pi>         ppi;
typedef vector<int>            vi;
typedef vector<string>         vs;
typedef vector<vi>             vvi;
typedef map<int, int>          mapi;
typedef set<int>               seti;
typedef multimap<int, int>     mmapi;    
typedef multiset<int>          mseti;
typedef long int               int32;
typedef unsigned long int      uint32;
typedef long long int          int64;
typedef unsigned long long int uint64;
 
template <typename T>
void display(const vector<T> &l) {
    cout << "\n" << "[ ";
    for (const auto &element: l) { cout << element << " "; }
    cout << "]";
}
 
void solve() {;
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       solve();
    }   
    return 0;
}
