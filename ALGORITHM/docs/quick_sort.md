### Quick Sort

- approach
    - what we do here is basically pass the array to partition fun
    - which pics pivot element and place it on it's correct position in array
    - and returns that index
    - then we can recursivelly solve other part of array 

```cpp
    void quick_sort(vector<int> arr, int low, int high) {
        if (i < j) {
            // after below opertation
            // element present at index pivot would be on correct position
            // so we just need to sort prev to pivot part 
            // and next to pivot part only 
            // which we can do recursivly 
            int pivot = partition(arr, low, high);

            // below calls will sort rest part of the array as well
            quick_sort(arr, low, pivot - 1);
            quick_sort(arr, pivot + 1, high);
        }
    }
```
```cpp
    int partition(vector<int> &arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (arr[i] <= pivot) i++;
            while (arr[j] > pivot) j--;

            if (i < j) 
                swap(arr[i], arr[j]);    
        }
        swap(arr[j], arr[low]);
        return j;
    }
```