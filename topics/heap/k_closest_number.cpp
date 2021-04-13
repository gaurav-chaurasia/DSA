#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]\n";

class Solution
{

public:
    // x --> closest to x
    // k --> k element
    // arr --> in the vector
    void k_closest_number(vector<int> arr, int k, int x)
    {
        int n = arr.size(); 
        priority_queue<pair<int, int>> max_heap;

        for (int i = 0; i < n; i++)
        {
            max_heap.push(make_pair(abs(arr[i] - x), arr[i]));

            if (max_heap.size() > k)
                max_heap.pop();
        }
        while(!max_heap.empty()) 
        {
            DEB(max_heap.top().second);
            max_heap.pop();
        }
    }
};

int main()
{
    Solution *SOL = new Solution();

    vector<int> input = {5, 6, 7, 7, 8, 9, 10};
    SOL->k_closest_number(input, 4, 7);

    delete SOL;
    return 0;
}
