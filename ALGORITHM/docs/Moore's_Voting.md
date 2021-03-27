## Moore's Voting algo 

- this algo is used to find mejority element from an array 
- in O(n) time complexity
- a mejority element is the one which accuers more then n/2 times in the list or array

- `count(element)` > `n/2` i.e. that is mejority element

### steps 
> First step is to find the cadidate  
> and then varify that cadidate  

#### example
```cpp
    vector<int> arr = {2, 3, 4, 3, 3};
    
    int n = arr.size();
    n/2 // 2
    count(3) > 2 

    // 3 is mejority element 
```

#### algo
```cpp
    #include <bits/stdc++.h>
    using namespace std;

    class Solution {

    public:
        int FIND_CE(vector<int> arr) {
            int n = arr.size();
            int ME = arr[0];
            int count = 1;

            for (int i = 1; i < n; i++) {
                if (ME == arr[i])
                    count++;
                else 
                    count--;

                if (count == 0) {
                    ME = arr[i];
                    count++;
                }
            }

            return ME;
        }

        int VERIFY_CE(vector<int> arr, int CE) {
            int n = arr.size();
            
            int count = 0;
            for (int i = 0; i < n; i++)
                if (arr[i] == CE)
                    count++;
                    
            return count > (n / 2) ? CE : -1;
        }

        int Moore() {
            int n; cin >> n;
            vector<int> arr(n);

            for (int i = 0; i < n; i++) cin >> arr[i];

            // mejority_element -> ME
            // candidate_element -> CE
            
            // this is the only potential candidate to be a ME
            int CE = FIND_CE(arr); 
            
            // below verifies CE is ME or not 
            int ME = VERIFY_CE(arr, candidate_element);

            return ME;
        }

    };

    
    int main() {
        Solution* SOL = new Solution();
        
        SOL->SOL_01();
        
        delete SOL;
        return 0;
    }

```