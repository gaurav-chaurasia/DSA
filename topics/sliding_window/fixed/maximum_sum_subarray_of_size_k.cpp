#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]\n";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

class Solution {

public:
    void maximum_sum_subarray_of_size_k(int n, vector<int> arr, int k) {
        int mx = INT_MIN;
        int sum = 0;
        int j = 0, i = 0;

        while (j < arr.size()) {
            sum += arr[j];
            if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {
                mx = max(sum, mx);
                sum -= arr[i];
                i++; j++;
            }
        }
        DEB(mx);
    }

};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* SOL = new Solution();
    
    int n = 7;
    int k = 3;
    vector<int> arr = {2, 5, 1, 8, 2, 9, 1};
    SOL->maximum_sum_subarray_of_size_k(n, arr, k);
    
    delete SOL;
    return 0;
}
