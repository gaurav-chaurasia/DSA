#include <iostream>
#include <string.h>
#include <bits/stdc++.h> 

using namespace std;

void pairsort(int a[], int b[], int n) { 
    pair<int, int> pairt[n]; 
  
    for (int i = 0; i < n; i++) { 
        pairt[i].first = a[i]; 
        pairt[i].second = b[i]; 
    } 
  
    sort(pairt, pairt + n); 
      
    for (int i = 0; i < n; i++) { 
        a[i] = pairt[i].first; 
        b[i] = pairt[i].second; 
    } 
}
int main () {
    
    int test_case_num {0};    // taking input for number of test case
    cin >> test_case_num;

    char jamie = 'J', cameron = 'C';
    bool jamie_busy = false, cameron_busy = false;
    for (int k=0; k<test_case_num; k++) {
        string str {0};
        bool possibility = true;
        int jamie_free_after=0, cameron_free_after=0;
        int num_act {0};
        cin >> num_act;
        int act_s[num_act], act_e[num_act];
        for ( int i=0; i<num_act; i++) {
            cin >> act_s[i] >> act_e[i];
        }
        
        pairsort(act_s, act_e, num_act);
        // start
        for (int i=0; i<num_act; i++) {
            //lets assignm it to c
            if (i == 0) {
                cameron_busy = true;
                cameron_free_after = act_e[0];
                str.push_back(cameron);
            }
            
            if ((i!=0) && i !=num_act-1) {
                if (act_s[i] >= cameron_free_after) {
                    if (cameron_free_after <= act_s[i]) {
                        cameron_busy = true;
                        cameron_free_after = act_e[i];
                        str.push_back(cameron);
                    }
                }
                if ((act_s[1] < act_e[0]) && jamie_free_after == 0) {
                    if (act_e[1] >= act_s[1]) {
                        jamie_busy = true;
                        jamie_free_after = act_e[1];
                        str.push_back(jamie);
                    }
                }
                if (act_s[i] >= jamie_free_after) {
                    jamie_busy = true;
                    jamie_free_after = act_e[i];
                    str.push_back(jamie);
                }
            }

            if (i == num_act-1) { //i =4
                if (act_s[i] >= cameron_free_after) {
                    cameron_busy = true;
                    cameron_free_after = act_e[i];
                    str.push_back(cameron);
                }
                if (act_s[i] < cameron_free_after) {
                    if (act_s[i] < jamie_free_after) {
                        possibility = false;
                        break;
                    }
                }
                if (act_s[i] < cameron_free_after) {
                    if (act_s[i] >= jamie_free_after) {
                        jamie_busy = true;
                        jamie_free_after = act_e[i];
                        str.push_back(jamie);
                    }
                }
            }
        }
        
        //end
        cout<<"Case #"<<k+1<<": ";
        if (possibility == true) {
            str.pop_back();
            cout << str << endl;
        }
        else {
            cout << "IMPOSSIBLE" << endl;
            str = "";
        }
        
    }
    return 0;
}