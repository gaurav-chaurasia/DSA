#include <bits/stdc++.h>
using namespace std;

typedef long long int          ll;
typedef unsigned long long int ull;
 
void solve() {
    int five = 0, ten = 0, n, ans = 1, temp;
	   cin >> n;
	   //int p[n];
	   //for(int i =0; i < n; i++)
    	   //cin >> p[i];
	   
	   while (n--) {
	       cin >> temp;
           if (ans == 0)
               continue;
	       if (temp == 5) {
    	       five++;
	       } else if(temp == 10) {
	           if (five > 0) {
	               ten++;
	               five--;
	           } else {
	               ans = 0;
                   continue; 
	           }
	       } else if (temp == 15) {
	           if (ten > 0) {
	               ten--;
	           } else {
	               if (five >= 2) {
	                   five -= 2;
	               } else {
	                   ans = 0;
	                   continue;
	               }
	           }
	       }
	   }
	   if (ans == 1)
    	   cout << "YES" << endl;
       else
           cout << "NO" << endl;
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       solve();
    }   
    return 0;
}
