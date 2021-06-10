// https://youtu.be/Ns4LCeeOFS4
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using ppi = pair<int, pi>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define endl '\n'
#define all(x) begin(x), end(x)
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9+7

class Solution {

public:
    // the problem is
    // you are given an array of numbers
    // and you have to find the lenght of longest increasing subsequenc

    // in these type of problem we can use the approach like
    // lenght at i'th index i.e. LIS ending at i'th index
    // also as this ending at i'th index means it must be included in LIS
    // 6, 2, 5, 1, 7, 4, 8, 3

    // LIS ending at i = 0; -> 1
    // LIS ending at i = 1; -> 1
    // LIS ending at i = 2; -> 2
    // LIS ending at i = 3; -> 1
    // LIS ending at i = 4; -> 3
    // LIS ending at i = 5; -> 2
    // LIS ending at i = 6; -> 4
    // LIS ending at i = 7; -> 2
    void longest_increasing_subsequence(vector<int> arr) {
        vector<int> LIS(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            LIS[i] = 1;

            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        for (int i: LIS) {
            cout << i << " ";
        } cout << endl;

        // for max LIS 
        int mx = INT_MIN;
        for (int i: LIS) 
            mx = max(mx, i);
        
        cout << mx << endl;
    }
};

 
int main() {
    Solution* SOL = new Solution();
    
    vector<int> arr = {6, 2, 5, 1, 7, 4, 8, 3};
    SOL->longest_increasing_subsequence(arr);
    
    delete SOL;
    return 0;
}
