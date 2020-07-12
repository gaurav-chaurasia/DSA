#include <bits/stdc++.h>
using namespace std;

#define sq(a)              (a)*(a)
#define PI                 3.1415926535897932384626433832795
#define MOD                1000000007
 
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n, size, count = 0, value1, value2;
    cin >> n;
    size = 4 * n - 1;
    vector <pair<int, int>> vertices1, vertices2;
    for (int i = 0; i < size; i++) {
        int x, y;
        cin >> x >> y;
        vertices1.push_back(make_pair(x, y));
        vertices2.push_back(make_pair(y, x));
    }
    sort(vertices1.begin(), vertices1.end());
    sort(vertices2.begin(), vertices2.end());
    for (int i = 0; i < size; i++) {
        if (vertices1[i].first == vertices1[i+1].first)
            count++;
        else { 
            count++;
            if (count % 2 == 1) {
                value1 = vertices1[i].first;
                // end = i;
                break;
            }
            count = 0;
        }
    }
    count = 0;
    for (int i = 0; i < size; i++) {
        if (vertices2[i].first == vertices2[i+1].first)
            count++;
        else { 
            count++;
            if (count % 2 == 1) {
                value2 = vertices2[i].first;
                // end = i;
                break;
            }
            count = 0;
        }
    }
    // for (int i = 0; i < size; i++) {
    //     if ((vertices[i-1].first != vertices[i].first) and i-1 >= 0)
    //         start1 = i;
    //     if (vertices[i].first == vertices[i+1].first)
    //         count++;
    //     else { 
    //         count++;
    //         end1 = i;
    //         if ((end1 - start1) == (end - start + 1)) {
    //             break;
    //         }
    //         count = 0;
    //     }
    // } 
    cout << value1 << " " << value2 << endl;
    // for (auto it : vertices) {
    //     cout << it.first << " " << it.second << endl;
    // }
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       solve();
    }   
    return 0;
}
