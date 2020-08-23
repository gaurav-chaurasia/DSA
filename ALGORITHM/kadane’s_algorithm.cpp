#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
class Algorithms {
    public:
        /**
         * basically kadane's algorithm tracks the total sum so far and if it gets negative 
         * then it's not worth to add it into total sum while
         * @max_so_far keep note of max  
         */
       
        /**
         *  Initialize:
         *       max_so_far = 0
         *       max_ending_here = 0
         *
         *   Loop for each element of the array
         *      (a) max_ending_here = max_ending_here + a[i]
         *      (b) if(max_so_far < max_ending_here)
         *               max_so_far = max_ending_here
         *      (c) if(max_ending_here < 0)
         *               max_ending_here = 0
         *   return max_so_far
         */
        int kadanes (vector<int> arr) {
            int size = arr.size();
            int sum = 0;
            int max_so_far = INT_MIN;
            for (int i=0; i < size; i++) {
                sum += arr[i];
                max_so_far = max(max_so_far, sum);
                if (sum < 0) sum = 0;
            }            
            return max_so_far; 
        }
};
 
int main() {
    Algorithms obj;
    vector<int> arr{1, 2, 3, -2, 5};
    int ans = obj.kadanes(arr);
    return 0;
}
