#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void solve(vector<int> &vn, vector<int> &vm)
{
    int left[vn.size()];
    int right[vn.size()];
    int l = -1;
    for (int i = 0; i < vn.size(); i++)
    {
        if (vn[i] == 1)
            l = i;
        left[i] = l;
    }
    int r = -1;
    for (int i = vn.size() - 1; i >= 0; i--)
    {
        if (vn[i] == 2)
            r = i;
        right[i] = r;
    }
    vector<int> res;

    for (int i = 0; i < vm.size(); i++)
    {
        int temp = vm[i] - 1;
        if (vm[i] == 1)
            res.push_back(0);

        else if (left[temp] == -1 and right[temp] == -1)
            res.push_back(-1);
        else if (left[temp] == -1 and right[temp] != -1)
            res.push_back(right[temp] - vm[i] + 1);
        else if (left[temp] != -1 and right[temp] == -1)
            res.push_back(vm[i] - 1 - left[temp]);
        else
            res.push_back(min(vm[i] - 1 - left[temp], right[temp] - vm[i] + 1));
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> vn;
        vector<int> vm;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            vn.push_back(temp);
        }
        for (int i = 0; i < m; i++)
        {
            int temp;
            cin >> temp;
            vm.push_back(temp);
        }
        solve(vn, vm);
        cout << endl;
    }
    return 0;
}