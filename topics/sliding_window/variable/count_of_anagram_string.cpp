// bigstring = "abcabcabccbba" -> n
//         abc, bca, cab,  
// smallstring = "abc" -> m

// O(n)
// O(m)

// mp = {(a, 1), (b, 1), (c, 1)};

// i   
// a b d c a b c a b c c b b a 
//     j 

// a = 0;
// count = 3;
// ans.push_back(s.substr(i, j - i + 1));
// ans = {abc, }


#include <bits/stdc++.h>
using namespace std;

vector<string> find_common(string str, string pat) {
    vector<string> ans;
    int n = str.size();
    int m = pat.size();

    unordered_map<char, int> mp;
    for (int i = 0; i < m; i++)  mp[pat[i]]++;

    int count = mp.size();
    int i = 0; 
    int j = 0;

    while (j < n) {
        if (mp.find(str[j]) != mp.end()) {
            if (mp[str[j]] == 0) {
                while (i < j) {
                    if (str[i] == str[j]) {
                        mp[str[i]]++;
                        if (mp[str[i]] == 1) {
                            count++;
                        }
                        i++;
                        break;
                    }
                    mp[str[i]]++;
                    if (mp[str[i]] == 1) {
                        count++;
                    }
                    i++;
                }
            }

            mp[str[j]]--;
            if (mp[str[j]] == 0) {
                count--;
            }
        }
        else {
            while(i < j) {
                mp[str[i]]++;
                if (mp[str[i]] == 1) {
                    count++;
                }
                i++;
            }
            i++;
            j++;
            continue;
        }

        if (count > 0) {
            j++;
        }
        else if (count == 0) {
            string temp = str.substr(i, j - i + 1);
            ans.push_back(temp);
            cout << temp << endl;
            while (count <= 0) {
                mp[str[i]]++;
                if (mp[str[i]] == 1) {
                    count++;
                }
                i++;
            }
            j++;
        }
    }

    return ans;
}
 
int main() {
    vector<string> ans = find_common("abacbabc", "abc");
    
    for (string it: ans) {
        cout << it << " ";
    }

    return 0;
}