#include <bits/stdc++.h>
 
using namespace std;
#define w(x) int x; cin>>x; while(x--)

typedef long long ll;
typedef unsigned long long ull;
/**Question:
 * Input:
 *      screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
 *                      {1, 1, 1, 1, 1, 1, 0, 0},
 *                      {1, 0, 0, 1, 1, 0, 1, 1},
 *                      {1, 2, 2, 2, 2, 0, 1, 0},
 *                      {1, 1, 1, 2, 2, 0, 1, 0},
 *                      {1, 1, 1, 2, 2, 2, 2, 0},
 *                      {1, 1, 1, 1, 1, 2, 1, 1},
 *                      {1, 1, 1, 1, 1, 2, 2, 1},
 *                      };
 *      x = 4, y = 4, newColor = 3
 *  The values in the given 2D screen indicate colors of the pixels.
 *  x and y are coordinates of the brush, newColor is the color that
 *  should replace the previous color on screen[x][y] and all surrounding
 *  pixels with same color.
 *  Output:
 *  Screen should be changed to following.
 *      screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
 *                      {1, 1, 1, 1, 1, 1, 0, 0},
 *                      {1, 0, 0, 1, 1, 0, 1, 1},
 *                      {1, 3, 3, 3, 3, 0, 1, 0},
 *                      {1, 1, 1, 3, 3, 0, 1, 0},
 *                      {1, 1, 1, 3, 3, 3, 3, 0},
 *                      {1, 1, 1, 1, 1, 3, 1, 1},
 *                      {1, 1, 1, 1, 1, 3, 3, 1},
 *                      };
**/

void print(const vector<vector<int>> &a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            cout << a[i][j] << " ";
        }
    }
}
 
void flood_fill_algorithm(vector<vector<int>> &a, int x, int y, int prev_color, int color) {
    
    if (x >= a.size() || y >= a[0].size() || x < 0 || y < 0) return;
    if (prev_color != a[x][y]) return;
    if (color == a[x][y]) return;
    
    a[x][y] = color;
    flood_fill_algorithm(a, x-1, y, prev_color, color);
    flood_fill_algorithm(a, x+1, y, prev_color, color);
    flood_fill_algorithm(a, x, y-1, prev_color, color);
    flood_fill_algorithm(a, x, y+1, prev_color, color);
}
 
int main() {
    w(t) {
        int n, m, x, y, color, prev_color;
        cin >> n >> m;
        
        vector<vector<int>> grid(n, vector<int> (m)); // reading 2D grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        cin >> x >> y >> color;
        prev_color = grid[x][y];
        
        flood_fill_algorithm(grid, x, y, prev_color, color);
        print(grid);

        cout << endl;
    }   
    return 0;
}
