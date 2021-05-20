// https://codeforces.com/contest/1516/problem/D
/*
    points to note here 
    - let say we have arr[] = {2 3 10 7 5 14}
    - according to problem
    - when we select subrange in l=1 to r=6 say 
        - [2], [3, 10, 7], [5, 14]
        - for all these subranges
        - product of subrange = LCM(subrange)
        - a1 * a2 * a3 .. an = LCM(a1, a2, a3, ...., an);
        - i.e. 
        - 3 * 10 * 7 = LCM(3, 10, 7) ==> 210
        - as we know 
        - a * b * c ... * z = LCM(a * b * c ... * z) * GCD(a * b * c ... * z)
        - to make  product(subrange) = LCM(subrange) ==> GCD(subrange) has to be 1
        - which indicates that all these nubers are co-prime
*/
#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define w(x)   int x; cin>>x; while(x--)
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    void SOL_01() {
        
    }

};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* SOL = new Solution();
    
    w(t) {
       SOL->SOL_01();
    }
    
    delete SOL;
    return 0;
}
