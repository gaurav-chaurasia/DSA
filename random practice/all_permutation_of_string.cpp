#include <bits/stdc++.h>
 
using namespace std;

#define w(x)            int x; cin>>x; while(x--) 
typedef long long ll;
typedef unsigned long long ull;


// method 1
void print_permutations(string str, int start, int end, vector<string>& all_permutation) {
    if  (start == end) {
        all_permutation.push_back(str);
    } else {
        for (int i = start; i <= end; i++) {
            swap(str[start], str[i]);
            print_permutations(str, start+1, end, all_permutation);
            swap(str[start], str[i]);
        }
    }
}
 
// method 2
void print_permutations_1 (string str) {
    sort(str.begin(), str.end());
    do {
        cout << str << " ";
    } while (std::next_permutation(str.begin(), str.end()));
}
 
int main() {
    w(t) {
        vector<string> all_permutation;
        string str; cin >> str;
        print_permutations(str, 0, str.size()-1, all_permutation);
        sort(all_permutation.begin(), all_permutation.end());
        for (auto it: all_permutation) 
            cout << it << " ";
        cout << endl;
    }   
    return 0;
}
