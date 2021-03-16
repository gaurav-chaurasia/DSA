#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;

class Solution {
    
public:
    // below ans gives TLE 😭
    void SOL_01() {
        int ans = 0;
        int n; cin >> n;
        list<int> num;

        for (int i = 0; i <n; i++) {
            int temp; cin >> temp;
            num.push_back(temp);
        }


        // TLE
        while (!num.empty()) {
            int temp = num.front();
            num.pop_front();

            for (list<int>::iterator i= num.begin(); i != num.end();) {
                if (temp + 1 == *i) { 
                    temp = *i;
                    auto it = i;
                    i++;
                    num.erase(it);
                    continue;
                }
                i++;
            }
            ans++;
        }

        cout << ans << endl;
    }

    void SOL_02() {

    }
};

int main() {
    Solution* SOL1 = new Solution();

    SOL1->SOL_01();
    // SOL1->SOL_02();
    // SOL1->SOL_03();
    // SOL1->SOL_04();

    return 0;
}
