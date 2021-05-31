#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

class Solution {

public:
    // question is 
    // we will be given an array @arr of numbers and a total @k
    // we are suppose to find the max subarray with sun = @k
    void largest_subarray_of_sum_k(int n, vector<int> arr, int k) {
        int mx_subarray_len = 0;
        int i = 0, j = 0;
        ll sum = 0;

        while (j < arr.size()) {
            sum += arr[j];

            if (sum < k) {
                j++;
            }
            else if (sum == k) {
                // calculating answer
                mx_subarray_len = max(mx_subarray_len, j - i + 1);
                j++;
            }
            else {
                while (sum > k) {
                    sum -= arr[i];
                    i++;
                }
                j++;
            }
        }

        DEB(mx_subarray_len);
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    vector<int> arr = {4, 1, 1, 1, 2, 3, 5};
    SOL->largest_subarray_of_sum_k(arr.size(), arr, 5);
    
    delete SOL;
    return 0;
}
