/**
 * There are given n ropes of different lengths, 
 * we need to connect these ropes into one rope. 
 * The cost to connect two ropes is equal to the sum of their lengths. 
 * We need to connect the ropes with minimum cost
 * 
 * 
*/
#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    int connect_rope_minimize_cost(vector<int> arr)
    {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < n; i++)
            min_heap.push(arr[i]);
        
        int res = 0;
        while(min_heap.size() >= 2)
        {
            int x = min_heap.top();
            min_heap.pop();
            int y = min_heap.top();
            min_heap.pop();

            res += (x + y);
            min_heap.push(x + y);
        }
        return res;
    }
};

int main()
{
    Solution *SOL = new Solution();

    vector<int> input = {1, 2, 3, 4, 5};
    cout << SOL->connect_rope_minimize_cost(input);

    delete SOL;
    return 0;
}
