#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main () {

    int test_case_num {0};    // taking input for number of test case
    cin >> test_case_num;
    
    for (int i=0; i<test_case_num; i++) {
        
        int num_row_col {0}; // taking input for number of rows and column
        cin >> num_row_col;
        
        int matrix[num_row_col][num_row_col] {}; //dcla and initializing matrix with zero
        
        for (int row=0;  row<num_row_col; row++) {
            for (int col=0; col<num_row_col; col++) {
                
                cin >> matrix[row][col];
            }
        }
        // input for test case i teminate her and proccess starts
        int trace {0}, num_row {0}, num_col {0};
        ////below code calculates trace
        for (int i=0; i<num_row_col; i++) {
            trace += matrix[i][i];
        }
        //below code checks repeatation in rows
        for (int row=0;  row<num_row_col; row++) {
            int temp_arr[num_row_col] {0};
            for (int col=0; col<num_row_col; col++) {
                
                temp_arr[col] = matrix[row][col];
            }
            
            sort(temp_arr, temp_arr+num_row_col);
            
            for (int i=0; i<num_row_col; i++) {
                if (i<num_row_col-1) {
                    if (temp_arr[i] == temp_arr[i+1]){
                        num_row++;
                        break;
                    }
                }
            }
        }
        //below code checks repeatation in columns
        for (int row=0;  row<num_row_col; row++) {
            int temp_arr[num_row_col] {0};
            for (int col=0; col<num_row_col; col++) {
                
                temp_arr[col] = matrix[col][row];
            }
        
            sort(temp_arr, temp_arr+num_row_col);
            
            for (int i=0; i<num_row_col; i++) {
                if (i<num_row_col-1) {
                    if (temp_arr[i] == temp_arr[i+1]){
                        num_col++;
                        break;
                    }
                }
            }
        }
        cout<<"Case #"<<i+1<<": "<<trace<<" "<<num_row<<" "<<num_col<<endl;
    }
    
    return 0;
}