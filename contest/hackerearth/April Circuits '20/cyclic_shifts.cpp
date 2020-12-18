#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define BIT_SIZE 16

int main()
{

    int test_case_num{0}; // taking input for number of test case
    cin >> test_case_num;

    for (int k = 0; k < test_case_num; k++)
    {
        int N, m;
        char c;

        cin >> N >> m >> c;
        bitset<BIT_SIZE> binary_N(N);

        if (c == 'L' || c == 'l')
        {
            binary_N = (binary_N << m) | (binary_N >> (BIT_SIZE - m));
            // peform cyclic shift 
        }
        if (c == 'R' || c == 'r')
        {
            binary_N = (binary_N >> m) | (binary_N << (BIT_SIZE - m));
        }
        cout << binary_N.to_ulong() << endl;
        //  .to_ulong() converts binary to decimal
    }

    return 0;
}