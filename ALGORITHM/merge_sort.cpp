#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
class Algorithms {
    public:
        // Question3 -- implementation of merge sort
        // Given an vector of integers nums, sort the array in ascending order.
        vector<int> merge(vector<int> a, vector<int> b) {// no need to pass by reference
            vector<int> ab;
            int i = 0, j = 0;
            while (i < a.size() and j < b.size()) {
                if (a[i] <= b[j]) {
                    ab.push_back(a[i]);
                    i++;
                } else {
                    ab.push_back(b[j]);
                    j++;
                }
            }
            while (i < a.size()) {
                ab.push_back(a[i]);
                i++;
            }
            while (j < b.size()) {
                ab.push_back(b[j]);
                j++;
            }
            return ab;
        }
        vector<int> merge_sort(vector<int>& arr) {
            if (arr.size() <= 1)
                return arr;
            int midle = (arr.size()) / 2;
            
            vector<int> left; // now we have left part and right part
            vector<int> right;
            for (int i = 0; i < midle; i++)
                left.push_back(arr[i]);
            for (int i = midle; i < arr.size(); i++)
                right.push_back(arr[i]);
            left = merge_sort(left);
            right = merge_sort(right);
            
            return merge(left, right);
        }
};
 
int main() {
    Algorithms obj;
    vector<int> arr{1, 2, 3, -2, 5};
    vector<int> result = obj.merge_sort(arr);
    return 0;
}
