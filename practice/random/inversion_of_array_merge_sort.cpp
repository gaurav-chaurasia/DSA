// // #include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// using namespace std;

#define setbits(x)      __builtin_popcountll(x) // gives number of set bits in a number
#define zrobits(x)      __builtin_ctzll(x) // gives number of leading zeros 
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x // set y precision after decimal 
#define mk(arr,n,type)  type *arr=new type[n]; // makes arr of size n 
#define EPS   			1e-9 // almost zero 
#define PI    			3.1415926535897932384626433832795
#define w(x)            int x; cin>>x; while(x--)
#define mod             1000000007 // 1e9+7
// #define int             long long
 
typedef long long ll;
typedef unsigned long long ull;

// // int merge_sort_inversion(vector<int> arr, vector<int> temp, int left, int right);
// // int merge(vector<int> arr, vector<int> temp, int left, int middle, int right);
 

// int merge(vector<int> arr, vector<int> temp, int left, int middle, int right) {
//     int i = left;
//     int j = middle;
//     int k = right;
//     int inversion_count = 0;
//     while (i < middle && j <= right) {
//         if (arr[i] <= arr[j]) {
//             temp[k++] = arr[i++];
//         } else {
//             temp[k++] = arr[j++];
//             inversion_count += middle - 1;
//         }
        
//         while (i <= middle - 1) 
//             temp[k++] = arr[i++]; 
//         while (j <= right) 
//             temp[k++] = arr[j++]; 
            
//         for (i = left; i <= right; i++) 
//             arr[i] = temp[i]; 
      
//         return inversion_count; 
//     }
// }


// int merge_sort_inversion(vector<int> arr, vector<int> temp, int left, int right) {
//     int inversion_count = 0;
    
//     if (arr.empty()) 
//         return inversion_count;
    
//     if (right > left) {
//         int middle = (right + left)/2;
        
//         inversion_count += merge_sort_inversion(arr, temp, left, middle);
//         inversion_count += merge_sort_inversion(arr, temp, middle+1, right);
        
//         inversion_count += merge(arr, temp, left, middle+1, right);
//         return inversion_count;
//     }
// }

#include <bits/stdc++.h> 
using namespace std; 
  
ll _mergeSort(int arr[], int temp[], int left, int right); 
ll merge(int arr[], int temp[], int left, int mid, int right); 
  
ll mergeSort(int arr[], int array_size) { 
    int temp[array_size]; 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  

ll _mergeSort(int arr[], int temp[], int left, int right) { 
    ll mid, inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
  
        inv_count += _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right); 
  
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 


ll merge(int arr[], int temp[], int left, int mid, int right)  { 
    int i, j, k; 
    ll inv_count = 0; 
  
    i = left;
    j = mid; 
    k = left; 
    
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 

 
int main() {
    w(t) {
       	// your code goes here!!!
        int n; cin >> n; 
        int arr[n], temp[n];
        for (int i =0; i < n; i++) cin >> arr[i];
        // int ans = 0;
        //for (int i= 0; i < n; i++) {
        //    for (int j = i+1; j < n ; j++) {
        //        if (arr[i] > arr[j]) ans++;
        //    }
        //}
        
        cout << _mergeSort(arr, temp, 0, n-1) << endl;
    }   
    return 0;
}
