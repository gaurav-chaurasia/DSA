#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;

typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    void SOL_01() {
        int n, k = 1; cin >> n >> k;
        vector<int> arr;

        for (int i = 1; i <= n; i++)
            arr.push_back(i);

        int start = 0;
        while (!arr.empty()) {
            start = (start + k) % arr.size();
            cout << arr[start] << " ";
            arr.erase(arr.begin() + start);
        }
        return;
    }
};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution* SOL = new Solution();
    SOL->SOL_01();
    
    delete SOL;
    return 0;
}
