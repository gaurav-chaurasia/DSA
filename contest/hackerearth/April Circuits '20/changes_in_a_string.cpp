#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int test_case_num{0}; // taking input for number of test case
    cin >> test_case_num;

    for (int k = 0; k < test_case_num; k++)
    {
        int size_string, 
            a_count = 0, 
            b_count = 0, 
            min_changes = 0;
        bool a_sub_count = false,
             b_sub_count = false;
        cin >> size_string;
        char arr[size_string];
        for (int i = 0; i < size_string; i++)
            cin >> arr[i];

        for (int i = 0; i < size_string; i++)
        {
            if (arr[i] == 'A')
                a_count++;
            b_count++;
        }
        if (a_count == 1 || b_count == 1)
        {
            if (arr[0] == 'A' || arr[size_string - 1] == 'B')
            {
                continue;
            }
        }
        if (a_count != 1 && b_count != 1)
        {
            if (a_count > b_count) {
                for (int i=0; i<size_string; i++)
                {
                    if (i >= a_count && arr[i] == 'B')
                        b_sub_count = true;
                }
            } else {
                for (int i = 0; i < size_string; i++)
                {
                    if (i < a_count && arr[i] == 'A')
                        a_sub_count = true;
                }
            }
        }

        for (int i = 0; i < size_string; i++)
        {
            if (arr[i] != 'A' && i < a_count)
            {
                arr[i] = 'A';
                min_changes++;
            }
            if (arr[i] != 'B' && i >= a_count)
            {
                arr[i] = 'B';
                min_changes++;
            }
        }
        cout << min_changes << endl;
    }
    return 0;
}
