#include <iostream>
#include <string.h>

using namespace std;

int main () {
    
    int test_case_num {0};    // taking input for number of test case
    cin >> test_case_num;
    
    for (int k=0; k<test_case_num; k++) {
        string str;
        cin >> str;
        string new_str;
        int str_len = str.length();
        for (int i=0; i<str_len; i++) {
            if (i == 0) {
                if (str.at(0) > '0') {
                    for (int j=0; j<str.at(0)-'0'; j++) {
                        new_str.push_back('(');
                    }
                    new_str.push_back(str.at(0));
                }
                if (str.at(0) == '0') {
                    new_str.push_back(str.at(0));
                }
                if (str_len == 1) {
                    if (str.at(0) > '0') {
                        for (int j=0; j<str.at(0)-'0'; j++) {
                            new_str.push_back(')');
                        }
                    }
                }
                if (str_len > 1) {
                    if (str.at(0) < str.at(1)){
                        for (int j=0; j<str.at(1)-str.at(0); j++) {
                            new_str.push_back('(');
                        }
                    }
                    if (str.at(0) > str.at(1)) {
                        for (int j=0; j<str.at(0)-str.at(1); j++) {
                            new_str.push_back(')');
                        }
                    }
                }
            }
            if (i != 0 && i != str_len-1) {
                if ((str.at(i) < str.at(i+1)) && str.at(i) != '0'){
                    new_str.push_back(str.at(i));
                    for (int j=0; j<str.at(i+1)-str.at(i); j++) {
                        new_str.push_back('(');
                    }
                }
                if  ((str.at(i) > str.at(i+1)) && str.at(i) != '0') {
                    new_str.push_back(str.at(i));
                    for (int j=0; j<str.at(i)-str.at(i+1); j++) {
                        new_str.push_back(')');
                    }
                }
                if ((str.at(i) == str.at(i+1)) && str.at(i) != '0') {
                    for (int j=0; j<str.at(i)-'0'; j++) {
                        new_str.push_back(str.at(i));
                    }
                }
                if (str.at(i) == '0') {
                    new_str.push_back(str.at(i));
                }
                if (str.at(i)=='0' && str.at(i+1)>'0') {
                    for (int j=0; j<str.at(i+1)-str.at(i); j++) {
                        new_str.push_back('(');
                    }
                }
            }
            if (i == str_len-1 && i != 0) {
                if (str.at(str_len-1) > '0') {
                    new_str.push_back(str.at(str_len-1));
                    for (int j=0; j<str.at(str_len-1)-'0'; j++) {
                        new_str.push_back(')');
                    }
                }
                if (str.at(i) == '0') {
                    new_str.push_back(str.at(i));
                }
            }
        }
        cout<<"Case #"<<k+1<<": ";
        cout << new_str << endl;
    }
    
    return 0;
}