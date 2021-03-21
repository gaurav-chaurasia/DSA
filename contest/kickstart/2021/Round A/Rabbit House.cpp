#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define w(x)   int x; cin>>x; while(x--)
typedef long long ll;
typedef unsigned long long ull;


ll res = 0;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


class Solution {
public:
    void SOL_01() {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> grid(r, vector<int>(c));
        priority_queue<tuple<int, int, int>> pq;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j  < c; j++) {
                cin >> grid[i][j];
                pq.emplace(grid[i][j], i, j);
            }
        }

        while (!pq.empty()) {
            auto [h, i, j] = pq.top();
            pq.pop();
            if (h < grid[i][j])
                continue;

            for (int k = 0; k < 4; ++k) {
                int ni = i + d[k][0], nj = j + d[k][1];
                if (ni < 0 || ni >= r || nj < 0 || nj >= c)
                    continue;

                if (h - grid[ni][nj] > 1) {
                    res += abs(1 - abs(grid[ni][nj] - grid[i][j]));
                    pq.emplace(h - 1, ni, nj);
                    grid[ni][nj] = h - 1;
                }
            }
        }
    }

};

 
int main() {
    Solution* SOL = new Solution();
    int n; cin >>n;
    for (int i = 1; i <= n; i++) {
        res = 0;
    
        SOL->SOL_01();
        cout << "Case #" << i << ": " << res << endl;
    }
    
    delete SOL;
    return 0;
}
