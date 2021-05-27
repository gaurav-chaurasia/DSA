#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define b(x) begin(x)
#define e(x) end(x)
// #define f first
// #define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

class Solution {

public:
    void maximum_of_all_subarray_of_size_k(vector<int> arr, int k = 3) {
        deque<int> dq;

        int i = 0, j = 0;
        while (j < arr.size()) {
            while (!dq.empty() and dq.back() < arr[j])
                dq.pop_back();
            
            dq.push_back(arr[j]);
            

            if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {
                cout << dq.front() << " ";

                if (arr[i] == dq.front())
                    dq.pop_front();
                
                j++;
                i++;
            }
        }
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    vector<int> arr = {3, 2, 1, -2, 5, 3, 6, 7};
    SOL->maximum_of_all_subarray_of_size_k(arr);
    
    delete SOL;
    return 0;
}
