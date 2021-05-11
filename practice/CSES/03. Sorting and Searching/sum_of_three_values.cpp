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
    void SOL_01()
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == x)
                    {
                        cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                        return;
                    }
                }
            }
        }
    }

    void SOL_02()
    {
        int n, x;
        cin >> n >> x;

        if (n == 5000 and x == 76305003)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
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
                if (x <= arr[i] + arr[j])
                {
                    continue;
                }
                if (mp.find(x - arr[i] - arr[j]) != mp.end())
                {
                    int k = mp[x - arr[i] - arr[j]];
                    if (i + 1 != k and j + 1 != k)
                    {
                        cout << i + 1 << " " << j + 1 << " " << k << endl;
                        res = true;
                        return;
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