#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using ppi = pair<int, pi>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second

const int MAX_CHAR = 256;
const int MOD = 1000000007;

class Solution {

public:
    void josephus_problem(vector<int> &arr, int index, int k) {
        if (arr.size() == 1) {
            cout << arr[0] << endl;
            return;
        }
        index = (index + k) % arr.size();
        arr.erase(arr.begin() + index);

        josephus_problem(arr, index, k);
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    int k = 2;
    vector<int> arr = {1, 2, 3, 4, 5};
    SOL->josephus_problem(arr, 0, k - 1);
    
    delete SOL;
    return 0;
}
