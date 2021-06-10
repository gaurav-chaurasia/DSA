#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

class Solution {

public:
    vector<int> insert_element_in_sorted_arr(vector<int> arr, int temp) {
        int n = arr.size();
        if (arr[n - 1] <= temp || n == 0) {
            arr.push_back(temp);
            return arr;
        }

        int last_element = arr[n - 1];
        arr.pop_back();
        arr = insert_element_in_sorted_arr(arr, temp);
        arr.push_back(last_element);

        return arr;
    }

    vector<int> sort_an_array_using_recursion(vector<int> arr) {
        int n = arr.size();
        if (n <= 1) 
            return arr;

        int last_num = arr[n - 1];
        arr.pop_back();
        vector<int> sorted_arr = sort_an_array_using_recursion(arr);

        // this fun will 
        return insert_element_in_sorted_arr(sorted_arr, last_num);
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    vector<int> arr = {1, 23, 12, 10, 5, 3, 4, 7, 9, 5};
    arr = SOL->sort_an_array_using_recursion(arr);
    for (int i: arr) DEB(i);

    delete SOL;
    return 0;
}
