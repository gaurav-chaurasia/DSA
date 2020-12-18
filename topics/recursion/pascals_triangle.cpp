#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

unordered_map<ll, ll> cache; // for memoization

class Solution{
    public:
        /*Quetion:1
            in pascal's triangle return all element in a given row
                            1                       -> row(0)
                        1       1                   -> row(1)
                    1       2       1               -> row(2)
                1       3       3       1           -> row(3)
            1       4       6       4       1       -> row(4)
        1       5       10      10      5       1   -> row(5)
                            .
                            .
                            .
                            .
                            so..on
        */
        vector<int> getRow(int rowIndex) {
            vector<int> row(rowIndex + 1);
            if (rowIndex == 0) { // base case
                row[0] = 1;
                return row;
            }
            if (rowIndex == 1) { // extra handeling
                row[0] = 1;
                row[1] = 1;
                return row;
            }
            vector<int> prev_row = getRow(rowIndex - 1);
            
            for (int i = 0; i <= prev_row.size(); i++) {
                if (i == 0 || i == prev_row.size())
                    row[i] = 1;
                else 
                    row[i] = prev_row[i] + prev_row[i - 1];
            }
            return row;
            // vector<int> ans(rowIndex+1);
            // ans[0] = 1;
            // for(int index=1; index<rowIndex+1; index++)
            //     ans[index]=(long)ans[index-1]*(rowIndex-index+1)/index;
            // return ans;
        }
};

 
int main() {
    // your code goes here!!!
    vector<int> row;
    Solution obj;
    row = obj.getRow(40);
    for (auto it : row)
        cout << it << " ";
    return 0;
}
