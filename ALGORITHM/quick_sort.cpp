#include <bits/stdc++.h>
using namespace std;
#define DEB(x) cout << "[ " << x << " ]";
#define endl '\n'

const int MAX_CHAR = 256;
const int MOD = 1000000007;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j) {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;

        if (i < j) 
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high) {
    if (low < high) {
        // here partition fucntion sort one element to it's correct place
        int pivot = partition(arr, low, high);

        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}
 
int main() {
    vector<int> arr = { 2, 1, 6, 10, 4, 1, 3, 9, 7 };
    quick_sort(arr, 0, arr.size() - 1);
    for (int i: arr) DEB(i);
    return 0;
}