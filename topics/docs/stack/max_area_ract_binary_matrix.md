### max_area_ract_binary_matrix    


>> [TO_LEARN](https://youtu.be/St0Jf_VmG_g?list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd)   
```py
              --------------
    row = 0   | 0, 1, 1, 0 | --> all these can be represented in the form of 1D array
    row = 1   | 1, 1, 1, 1 | -->
    row = 2   | 1, 1, 1, 1 | -->
    row = 3   | 1, 1, 0, 0 | -->
              --------------
    
    for example
    row = 0 --> histogram [0, 1, 1, 0] --> each element in this array represents height of the building
    row = 1 --> histogram [1, 2, 2, 1]
    row = 2 --> histogram [2, 3, 3, 2]
    row = 3 --> histogram [3, 4, 0, 0]
    
```
```cpp

    class Solution
    {

    public:
        // Nearest Smallest Element Left
        vector<int> nearest_smallest_element_to_left(vector<int> arr)
        {
            int n = arr.size();
            vector<int> v;
            stack<pair<int, int>> st;

            for (int i = 0; i < n; i++)
            {
                if (st.empty())
                {
                    v.push_back(-1);
                }
                else if (!st.empty() && st.top().first < arr[i])
                {
                    v.push_back(st.top().second);
                }
                else
                {
                    while (!st.empty() && st.top().first >= arr[i])
                        st.pop();

                    v.push_back(st.empty() ? -1 : st.top().second);
                }
                st.push({arr[i], i});
            }
            return v;
        }

        // Nearest Smallest Element Right
        vector<int> nearest_smallest_element_to_right(vector<int> arr)
        {
            int n = arr.size();
            vector<int> v;
            stack<pair<int, int>> st;

            for (int i = n - 1; i >= 0; i--)
            {
                if (st.empty())
                {
                    v.push_back(n);
                }
                else if (!st.empty() && st.top().first < arr[i])
                {
                    v.push_back(st.top().second);
                }
                else
                {
                    while (!st.empty() && st.top().first >= arr[i])
                        st.pop();

                    v.push_back(st.empty() ? n : st.top().second);
                }
                st.push({arr[i], i});
            }

            reverse(v.begin(), v.end());
            return v;
        }

        // MAH -> maximum area of histogram
        int max_area_of_histogram(vector<int> arr)
        {
            vector<int> left = nearest_smallest_element_to_left(arr);
            vector<int> right = nearest_smallest_element_to_right(arr);

            vector<int> width(arr.size());
            vector<int> area(arr.size());
            for (int i = 0; i < arr.size(); i++)
                width[i] = right[i] - left[i] - 1;

            for (int i = 0; i < arr.size(); i++)
                area[i] = width[i] * arr[i];

            int ans = INT_MIN;
            for (int it : area)
                ans = max(ans, it);

            return ans;
        }

        int make_matrix_to_array(vector<vector<int>> matrix) 
        {
            int row = matrix.size();
            int col = matrix[0].size();

            vector<int> building(col, 0);

            // coping first row
            for (int j = 0; j < col; ++j)
                building[j] = matrix[0][j];
            
            int ans = max_area_of_histogram(building);
            for (int i = 1; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                    building[j] = matrix[i][j] == 0 ? 0 : building[j] + matrix[i][j];
                
                ans = max(ans, max_area_of_histogram(building));
            }

            return ans;
        }

    };

    int main()
    {
        Solution *SOL = new Solution();

        vector<vector<int>> matrix = {
            {0, 1, 1, 0},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0}
        };
        
        int max_area = SOL->make_matrix_to_array(matrix);
        DEB(max_area);

        delete SOL;
        return 0;
    }

```