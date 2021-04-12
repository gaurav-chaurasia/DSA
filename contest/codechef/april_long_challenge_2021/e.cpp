#include <iostream>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define w(x)   int x; cin>>x; while(x--)
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    void SOL_01() {
        int row, col, k;
        int count = 0;
        cin >> row >> col >> k;

        vector<vector<int>> matrix(row, vector<int>(col));
        vector<vector<int>> row_sum(row, vector<int>(col));
        vector<vector<int>> col_sum(row, vector<int>(col));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> matrix[i][j];
                row_sum[i][j] = col_sum[i][j] = matrix[i][j];
                
                if (matrix[i][j] >= k)
                    ++count;
            }
        }
        
        for (int i = 0; i < row; ++i) 
            for (int j = 1; j < col; ++j) 
                row_sum[i][j] += row_sum[i][j - 1];

        for (int j = 0; j < col; ++j)
            for (int i = 1; i < row; ++i)
                col_sum[i][j] += col_sum[i - 1][j];


        int l = 2;
        while (l <= min(row, col)) {
            ll curr_grid_sum = 0;
            ll temp_sum;

            // calculate curr_grid_sum for first L x L grid
            // then add one rwo and remove one row on moving 

            for (int i = 0; i < l; ++i)
                for (int j = 0; j < l; ++j) 
                    curr_grid_sum += matrix[i][j];

            
            for (int i = 0; i + l - 1 < row; ++i) {

                if (i != 0) 
                    curr_grid_sum += (row_sum[i+l-1][l-1] - row_sum[i-1][l-1]);
                    
                if ((curr_grid_sum / (l * l)) >= k) {
                    count += col - l + 1;
                    continue;
                }
                // if (i != 0) {
                //     curr_grid_sum += (row_sum[i + l - 1][l - 1] - row_sum[i - 1][l - 1]);
                //     if ((curr_grid_sum / (l * l)) >= k) {
                //         count += col - l + 1;
                //         continue;
                //     }
                // }
                temp_sum = curr_grid_sum;
                for (int j = 1; j + l - 1 < col; ++j) {
                    // some how delete the one row from sum
                    // add one row to the sum 
                    // check avg and increment count
                    
                    ll dec = i == 0 ? col_sum[i + l - 1][j - 1] : col_sum[i + l - 1][j - 1] - col_sum[i - 1][j - 1];
                    ll inc = i == 0 ? col_sum[i + l - 1][j + l - 1] : col_sum[i + l - 1][j + l - 1] - col_sum[i - 1][j + l - 1];
                    temp_sum += (inc - dec);

                    if ((temp_sum / (l * l)) >= k) {
                        count += col - l + 1 - j;
                        break;
                    }
                }
            }

            ++l;
        }
        cout << count << "\n";
    }
    void NOT_MINE() {
        ll n, m, k;
        cin >> n >> m >> k;
        double arr[n + 1][m + 1];

        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    arr[i][j] = 0;
                else
                    cin >> arr[i][j];
            }
        }
        for (ll i = 0; i <= n; i++)
        {
            double prev = 0;
            for (ll j = 0; j <= m; j++)
            {
                arr[i][j] += prev;
                prev = arr[i][j];
            }
        }
        for (ll i = 0; i <= m; i++)
        {
            double prev = 0;
            for (ll j = 0; j <= n; j++)
            {
                arr[j][i] += prev;
                prev = arr[j][i];
            }
        }
        ll m_min = min(m, n);
        ll ans = 0;

        for (ll u = 1; u <= m_min; u++)
        {
            for (ll i = u; i <= n; i++)
            {
                for (ll j = u; j <= m; j++)
                {
                    if ((arr[i][j] + arr[i - u][j - u] - arr[i][j - u] - arr[i - u][j]) / (u * u) >= k)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
};

 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    Solution* SOL = new Solution();
    
    w(t) {
       SOL->SOL_01();
    }
    
    delete SOL;
    return 0;
}
