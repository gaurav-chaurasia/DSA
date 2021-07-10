#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

const int MAX_CHAR = 256;
const int MOD = 1000000007;

class Solution {

public:
    int binary_search_recursive(vector<int> arr, int start, int end, int target) {
        int mid = start + (end - start)/2;
        if (start > end) return -1;
        
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) return binary_search_recursive(arr, start, mid - 1, target);
        else return binary_search_recursive(arr, mid + 1, end, target);
    }
    
    int binary_search_iterative(vector<int> arr, int target) {
        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start)/2;

            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    }
};

 
int main() {
    Solution* SOL = new Solution();

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 14, 16, 19};
    int target; cin >> target;
    DEB(SOL->binary_search_iterative(arr, target));
    DEB(SOL->binary_search_recursive(arr, 0, arr.size()-1, target));

    delete SOL;
    return 0;
}
