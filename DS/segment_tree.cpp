#include <bits/stdc++.h>
using namespace std;

void build(vector<int> &arr, vector<int> &st, int s, int e, int idx) {
    if (s == e) {
        st[idx] = arr[s];
        return;
    }

    int mid = s + (e - s)/2;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    build(arr, st, s, mid, left);
    build(arr, st, mid + 1, e, right);

    st[idx] = st[left] + st[right];
}

void segment_tree(vector<int> arr, int n) {
    // number of element in segment tree would be less then 4*m
    vector<int> st(4*n, 0);

    // segment tree would be build after this call
    build(arr, st, 0, n - 1, 0);
}
 
int main() {
    vector<int> arr = {1, 3, 4, 7, 9, 14, 11, 4};
    segment_tree(arr, arr.size());
    return 0;
}