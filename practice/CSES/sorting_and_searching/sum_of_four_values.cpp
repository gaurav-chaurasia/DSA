#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second

class Solution
{

public:
    void SOL_02()
    {
        int n, x;
        cin >> n >> x;

        bool res = false;
        vector<int> arr(n);
        unordered_map<int, int> mp(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i - 1];
            mp[arr[i - 1]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (x < arr[i])
                    break;

                for (int k = j + 1; k < n; k++) 
                {   
                    if (x < arr[i] + arr[j])
                        break;
                    
                    if (x < arr[i] + arr[j] + arr[k])
                    {
                        continue;
                    }
                    if (mp.find(x - arr[i] - arr[j] - arr[k]) != mp.end())
                    {
                        int l = mp[x - arr[i] - arr[j] - arr[k]];
                        if (i + 1 != l and j + 1 != l and k + 1 != l)
                        {
                            cout << i + 1 << " " << j + 1 << " " <<  k + 1 << " " <<  l << endl;
                            res = true;
                            return;
                        }
                    }
                }
            }
        }

        if (!res)
            cout << "IMPOSSIBLE" << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    // SOL->SOL_01();
    SOL->SOL_02();

    delete SOL;
    return 0;
}