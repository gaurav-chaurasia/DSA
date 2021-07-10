#include <bits/stdc++.h>
using namespace std;
#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

const int MAX_N = 100005;
const int LOG = 17;

// sparse table
int m[MAX_N][LOG];
int bin_log[MAX_N];


// range minimum query
class RMQ {

public:
    void pre_compute(vector<int> arr) {
        int n = arr.size();

        // this table hold the values 
        for (int i = 2; i <= n; i++) 
            bin_log[i] = bin_log[i/2] + 1;

        for (int i = 0; i < n; i++) 
            m[i][0] = arr[i];
        
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1<<k) - 1 < n; i++) {
                m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    int query(int l, int r) {
        int lenght = r - l + 1;
        int k = bin_log[lenght];
        return min(m[l][k], m[r - (1<<k) + 1][k]);
    }

    // here in this problem 
    // u will be given a array and you have to ans 
    // Q queries 
    // in each query u have to give the min element in array in range => [a, b] 
    void range_min_query(vector<int> arr, int q) {
        
        pre_compute(arr);

        while(q--) {
            int qs, qe;
            cout << query(qs, qe) << endl;
        }
    }

};

 
int main() {
    RMQ* SOL = new RMQ();
    
    vector<int> arr = {1, 3, 4, 8, 6, 1, 4, 2};
    RMQ->range_min_query(arr, 10);
    
    delete SOL;
    return 0;
}
