#include <iostream>

using namespace std;

#define MAX_SIZE 1000000

bool isHappy(int arr[], int arr_start, int arr_end, int arr2[], int arr_len2)
{
    int count_arr[MAX_SIZE]{0}, happy = 0;

    // for (int i = 0; i < arr_len; i++)
    // cout << arr[i] << " ";
    // for (int i=0; i<arr_len; i++)
    // {
    //     int count = 1;
    //     for (int j=i+1; arr[i] == arr[j] && j < arr_len; j++)
    //     {
    //         // cout << arr[i] << "ith, " << arr[j];
    //         if (arr[i] == arr[j])
    //         {
    //             count++;
    //         }
    //         else 
    //         {
    //             break;
    //         }
    //     }
    //     if (count == arr[i])
    //         return true;
    //     else
    //         return false;
    // }

    for (int i=arr_start; i<arr_end; i++)
    {
        count_arr[arr[i]]++;
    }
    // for (int i = 0; i < arr_len; i++)
    // {
    //     cout << count_arr[arr[i]];
    // }
    // cout << endl;
    // for (int i = 0; i < arr_len; i++)
    // {
    //     cout << arr[i];
    // }
    // cout << endl;

    for (int i=arr_start; i<arr_end; i++)
    {
        if (count_arr[arr[i]] != arr[i])
        {
            // for (int j=0; j<arr_len2; j++)
            // {
            //     if (arr[i] != arr2[j]) 
            //     {
            //         happy = 1;
            //     }
            // }
            happy = 1;
        }
    }
    if (happy == 0)
        return true;
    else
        return false;

}

int main()
{
    int num1, num2, num_query;
    cin >> num1 >> num2;
    int arr1[num1], arr2[num2];

    for (int i = 0; i < num1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < num2; i++)
    {
        cin >> arr2[i];
    }

    cin >> num_query;

    for (int i = 0; i < num_query; i++)
    {
        int start, end, count = 1;
        bool happy;
        cin >> start >> end;
        // int arr[end - start + 1];

        // for (int i = start - 1, j = 0; i < end; i++, j++)
        // {
        //     arr[j] = arr1[i];
        // }
        cout << endl;
        happy = isHappy(arr1, start - 1, end, arr2, num2);
         if (happy)
            cout << '1';
        else
            cout << '0';
    }
    cout << endl;
    return 0;
}