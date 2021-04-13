#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    void k_largest_element(vector<int> arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < arr.size(); ++i)
        {
            min_heap.push(arr[i]);

            if (min_heap.size() > k)
                min_heap.pop();
        }

        cout << min_heap.top() << endl;
    }
};  

int main()
{
    Solution *SOL = new Solution();

    vector<int> input = {7, 10, 4, 3, 20, 15};
    SOL->k_largest_element(input, 3);

    delete SOL;
    return 0;
}
