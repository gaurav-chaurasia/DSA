#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


unordered_map<ll, ll> cache; // for memoization 

class Solution {
public:
    /*Quetion:2
        You are climbing a stair case. It takes n steps to reach to the top.
        Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

        as one can go from n to n-1 or n-2 
            so ans = 
    */
    int climb_stairs(int n) {
        int ans;
        if (n <= 2) return n;
        if (cache.find(n) != cache.end()) return cache[n];
        else {
            ans = climb_stairs(n-1) + climb_stairs(n-2);
            cache[n] = ans;
            return ans;
        }
    }
};
 
int main() {
    // your code goes here!!!
    Solution obj;
    int steps = obj.climb_stairs(40);
    cout << steps << endl;
    return 0;
}
