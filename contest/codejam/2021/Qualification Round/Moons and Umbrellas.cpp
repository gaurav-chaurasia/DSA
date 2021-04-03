#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL() cout << endl;
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
typedef long long ll;
typedef unsigned long long ull;

ll ANS = INT_MAX;
char ch[] = {'C', 'J'};

class Solution
{

public:
    void REQ_SOL(int start, string &str, int x, int y)
    {
        // DEB(start);DEB(str);NL();
        int n = str.size();
        if (start >= n)
        {
            // count and check ANS
            ll ans = 0;
            int i, j;
            for (j = 1; j < str.size(); j++)
            {
                i = j - 1;
                if (str[i] == ch[0] and str[j] == ch[1])
                    ans += x;

                if (str[i] == ch[1] and str[j] == ch[0])
                    ans += y;
            }
            ANS = min(ANS, ans);

            return;
        }

        if (str[start] != '?')
            REQ_SOL(start + 1, str, x, y);
        else
        {
            for (int i = 0; i < 2; i++)
            {
                str[start] = ch[i];
                REQ_SOL(start + 1, str, x, y);
            }
        }

        // REQ_SOL(++start, str, x, y);
        return;
    }

    ll SOL_01()
    {
        int x, y;
        cin >> x >> y;
        string str;
        cin >> str;

        if (str.size() == 1)
            return 0;

        REQ_SOL(0, str, x, y);

        ll res = ANS;
        ANS = INT_MAX;
        return res;
    }

    ll SOL_02()
    {
        int x, y;
        cin >> x >> y;
        string str;
        cin >> str;

        ll ans = 0;
        int prev = 'I';
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'C')
            {
                if (prev == 'J')
                {
                    ans += y;
                }
                prev = 'C';
            }
            else if (str[i] == 'J')
            {
                if (prev == 'C')
                {
                    ans += x;
                }
                prev = 'J';
            }
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
        // ll res = SOL->SOL_01();
        ll res = SOL->SOL_02();
        cout << "Case #" << i << ": " << res << endl;
    }

    delete SOL;
    return 0;
}
