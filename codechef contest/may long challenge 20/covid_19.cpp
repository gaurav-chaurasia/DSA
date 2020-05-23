#include <iostream>
#include <vector>
using namespace std;

int solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int covid_positive[n]{};

    for (int i = 0; i < n; i++)
    {
        if (i == 0 && arr[i + 1] - arr[i] <= 2)
            covid_positive[i] = 1;
        if (i == n - 1 && arr[i] - arr[i - 1] <= 2)
            covid_positive[i] = 1;
        if ((arr[i + 1] - arr[i] <= 2 || arr[i] - arr[i - 1] <= 2) && i != 0 && i != n - 1)
            covid_positive[i] = 1;
    }

    // for minimum number of positive covid-19
    int min = 10, min_count[n]{};
    for (int i = 0; i < n; i++)
        if (covid_positive[i] == 0)
        {
            min = 0;
            break;
        }

    if (min != 0)
    {
        for (int i = 0, j = 0; i < n - 1; i++)
        {
            if (arr[i + 1] - arr[i] <= 2)
                min_count[j]++;
            else
                j++;
        }
        for (int i = 0; i < n; i++)
            if (min > min_count[i] && min_count[i] != 0)
                min = min_count[i];
    }

    // for number of infacted people
    int max = 0, max_count[n]{};
    ;

    for (int i = 0, j = 0; i + 1 < n; i++)
    {
        if (arr[i + 1] - arr[i] <= 2)
            max_count[j]++;
        else
            j++;
    }
    for (int i = 0; i < n; i++)
        if (max < max_count[i])
            max = max_count[i];
    max += 1;
    min += 1;
    cout << min << " " << max << endl;
}

int main()
{
    int t{0};
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
