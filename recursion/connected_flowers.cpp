#include <bits/stdc++.h>
 
using namespace std;
#define w(x)            int x; cin>>x; while(x--)
#define deb(x)      	cout << #x << "=>" << x << endl;// print variable and it's value x=>5
 
typedef long long ll;
typedef unsigned long long ull;

/**
 * you are given a grid M x N, each cell hase some integer value which represent a flower
 * value in cell refers to a type of flower ,
 * i.e. all cell with value <- 1 would represent one type of flower
 * and similarly all cell with value <- 2 would represent another type of flower
 * 
 * task is to find biggest connecting chunk not with not more then two type of flower 
 * 
 *   {
 *      1 | 1 | 3 | 8
 *      - + - + - + -
 *      2 | 1 | 1 | 2
 *      - + - + - + -
 *      3 | 2 | 4 | 1
 *   } 
 *      
 *     => ans 1 1 
 *            2 1 1 2 => count <- 8 
 *              2   1
*/

bool in_bound(int x, int y, int row, int col) {
    return x>=0 and y>=0 and x <row and y < col;
}

int max_collection_of_one_type = INT_MIN;
void flood_fill(vector<vector<int>> grid, vector<vector<int>> &path, int x, int y, int val, vector<vector<int>> &fix)
{
    int row = grid.size();
    int col = grid[0].size();

    if (x<0 || y <0 || x >=row || y>=col) {
        int sum = 0;
        for (int i = 0; i < row; i++) 
            for (int j = 0; j < col; j++) 
                if (path[i][j] == 1) sum++;
        if (sum > max_collection_of_one_type) {
            max_collection_of_one_type = max(max_collection_of_one_type, sum);
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    if (path[i][j] == 1)
                        fix[i][j] = 1;
        }
        return;
    
    } 
    if (path[x][y] == 1) return;
    if (grid[x][y] != val) return;

    path[x][y] = 1;
    flood_fill(grid, path, x+1, y, grid[x][y], fix);
    flood_fill(grid, path, x-1, y, grid[x][y], fix);
    flood_fill(grid, path, x, y+1, grid[x][y], fix);
    flood_fill(grid, path, x, y-1, grid[x][y], fix);
    path[x][y] = 0;
}

void solve(vector<vector<int>> grid, int row, int col) {
    int temp = 0;
    vector<vector<int>> path(row, vector<int>(col, 0)); // temprory variable wiche strore path in backtraking
    vector<vector<int>> fix(row, vector<int>(col, 0));  // @fix wherever we get a complete path with more value we'll save it in
    flood_fill(grid, path, 0, 0, grid[0][0], fix);

    unordered_map<int, int> adjacent_flowers;
    for (int i = 0; i < row; i ++) // traversing to grid and counting adjacents 
        for (int j = 0; j < col; j++)
            if (fix[i][j] != 1) {
                if ((in_bound(i - 1, j, row, col) and fix[i - 1][j] == 1) ||
                    (in_bound(i + 1, j, row, col) and fix[i + 1][j] == 1) ||
                    (in_bound(i, j + 1, row, col) and fix[i][j + 1] == 1) ||
                    (in_bound(i, j - 1, row, col) and fix[i][j - 1] == 1)) {
                    adjacent_flowers[grid[i][j]]++;
                    continue;
                }
            }
    for (auto it : adjacent_flowers) {
        temp = max(temp, it.second);
    }
    cout << "ans: " << max_collection_of_one_type + temp << endl;
}

int main() {
	// c_p_c();
    w(t){
       int m, n; cin >> m >> n; 
       vector<vector<int>> grid(m, vector<int>(n));
       for (int i = 0; i < m; i++) 
           for (int j = 0; j < n; j++) 
               cin >> grid[i][j];
       
       solve(grid, m, n);

    }   
    return 0;
}
