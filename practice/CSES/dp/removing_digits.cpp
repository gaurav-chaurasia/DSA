#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
int ans = INT_MAX;
class Solution
{
public:
    int SOL_01(int num)
    {
        vector<int> dp(num + 1);

        for (int i = 1; i <= num; i++)
        {
            int temp = i;
            int min_steps = INT_MAX;
            while (temp != 0)
            {
                int di = temp % 10;
                temp = temp / 10;
                if (di == 0) 
                    continue;
                
                min_steps = min(min_steps, 1 + dp[i - di]);
            }
            dp[i] = min_steps;
        }
        return dp[num];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    int n;
    cin >> n;
    cout << SOL->SOL_01(n) << endl;

    delete SOL;
    return 0;
}
