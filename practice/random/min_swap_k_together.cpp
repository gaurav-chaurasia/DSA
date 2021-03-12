// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;

int minSwap(int *arr, int n, int k);

int main() {
	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}

int minSwap(int *arr, int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) 
            count++;
    }
    
    int num_more = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] > k)
            num_more++;
    }
    int MIN = num_more;
    for (int i = 0, j = count; j < n; i++, j++) {
        
        if (arr[i] > k)
            num_more--;
            
        if (arr[j] > k)
            num_more++;
        
        MIN = min(MIN, num_more);
    }
    
    return MIN;
}
