/**
 * Given an array of n elements, 
 * where each element is at most k away from its target position, 
 * devise an algorithm that sorts in O(n log k) time. 
 * For example, let us consider k is 2, 
 * an element at index 7 in the sorted array, 
 * can be at indexes 5, 6, 7, 8, 9 in the given array
*/

#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]\n";
typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    void sort_k_sorted_array(vector<int> arr, int k)
    {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < n; i++)
        {
            min_heap.push(arr[i]);
            if (min_heap.size() > k) 
            {
                DEB(min_heap.top());
                min_heap.pop();
            }
        }
        while(!min_heap.empty()) 
        {
            DEB(min_heap.top());
            min_heap.pop();
        }
    }
};

int main()
{
    Solution *SOL = new Solution();

    vector<int> input = {6, 5, 3, 2, 8, 10, 9};
    SOL->sort_k_sorted_array(input, 3);

    delete SOL;
    return 0;
}
