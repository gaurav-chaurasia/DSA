// find first and last occurrence of an element 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

const int MAX_CHAR = 256;
const int MOD = 1000000007;

class Solution {

public:
    int first_occurrence_of_element(vector<int> arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            int item = arr[mid];

            if (item == target) {
                ans = mid;
                end = mid - 1;
            }
            else if (item > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }

};

 
int main() {
    Solution* SOL = new Solution();

    vector<int> arr = {1, 2, 2, 2, 5, 6, 7, 8, 9, 9, 9, 9, 9, 10, 11, 19};
    int target; cin >> target;
    DEB(SOL->first_occurrence_of_element(arr, target));
    
    delete SOL;
    return 0;
}
