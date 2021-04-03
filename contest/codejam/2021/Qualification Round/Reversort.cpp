#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class Solution
{

public:
    int SOL_01()
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans = 0;
        int j, i;
        for (i = 0; i < n - 1; i++)
        {
            int index = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[index])
                {
                    index = j;
                }
            }
            ans += abs(index - i + 1);
            reverse(arr.begin() + i, arr.begin() + index + 1);
        }
        return ans;
    }
};

int main()
{
    Solution *SOL = new Solution();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int res = SOL->SOL_01();
        cout << "Case #" << i << ": " << res << endl;
    }

    delete SOL;
    return 0;
}
