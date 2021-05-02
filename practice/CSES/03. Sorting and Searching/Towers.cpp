#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;

typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    void SOL_01()
    {
        int n, temp; cin >> n;
        multiset<int> ans;
        for (int i = 0; i < n; i++) 
        {
            cin >> temp;
            auto it = ans.upper_bound(temp);

            if (it == ans.end())
                ans.insert(temp);
            else
            {
                ans.erase(it);
                ans.insert(temp);
            }
        }
        cout << ans.size() << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    SOL->SOL_01();

    delete SOL;
    return 0;
}
