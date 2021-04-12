#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    // returns vector storing max elment in right to each element
    vector<int> get_max_right(vector<int> arr) {
        int n = arr.size();
        vector<int> l(n);

        l[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) 
            l[i] = max(l[i+1], arr[i]);
        
        return l;
    }
    // returns vector storing max elment in left to each element
    vector<int> get_max_left(vector<int> arr) {
        int n = arr.size();
        vector<int> r(n);

        r[0] = arr[0];
        for (int i = 1; i < n; i++)
            r[i] = max(r[i-1], arr[i]);

        return r;
    }

    void rain_water_trapping(vector<int> arr) {
        vector<int> max_r = get_max_right(arr);
        vector<int> max_l = get_max_left(arr);
        vector<int> water(arr.size());

        // water over each building
        for (int i = 0; i < arr.size(); ++i)
            water[i] = min(max_l[i], max_r[i]) - arr[i];
        
        int ans = 0;
        for (int it : water)
            ans += it;
        
        DEB(ans);
    }

};

 
int main() {
    Solution* SOL = new Solution();

    vector<int> input = {3, 0, 0, 2, 0, 4};

    SOL->rain_water_trapping(input);
    
    delete SOL;
    return 0;
}
