#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    void k_smallest_element(vector<int> arr, int k) {
        priority_queue<int> max_heap;

        for (int i = 0; i < arr.size(); ++i) {
            max_heap.push(arr[i]);

            if (max_heap.size() > k)
                max_heap.pop();
        }

        cout << max_heap.top() << endl;
    }
};

 
int main() {
    Solution* SOL = new Solution();
    
    vector<int> input = {7, 10, 4, 3, 20, 15};
    SOL->k_smallest_element(input, 3);

    delete SOL;
    return 0;
}
