#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
#define w(x)   int x; cin>>x; while(x--)
typedef long long ll;
typedef unsigned long long ull;

class Solution {

public:
    bool check_subseq(string str, string s) {
        int i = 0, j = 0;
        while (str[i] != NULL and s[j] != NULL) {
            if(str[i] == s[j]){
                i++;
                j++;
            }
            else
                i++;
        }

        return (j == s.length() ? true : false);
    }
    void SOL_01() {
        string str; cin >> str;
        queue<string> q;
        cout << "0" << endl;

        // if (!check_subseq(str, "0")) {
        //     cout << "0" << endl;
        //     return;
        // }
        q.push("1");
    
        while (true) {
            string s1 = q.front();
            q.pop();
            // check subsequence 
            // DEB(s1);
            if(s1.size() > 60)
                return;
            
            cout << s1 << endl;

            // if (!check_subseq(str, s1)) {
            //     cout << s1 << endl;
            //     return;
            // }

            string s2 = s1; 
            q.push(s1.append("0"));
            q.push(s2.append("1"));
        }
    }

};

 
int main() {
    Solution* SOL = new Solution();
    
    w(t) {
       SOL->SOL_01();
    }
    
    delete SOL;
    return 0;
}
