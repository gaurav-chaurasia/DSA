#include<bits/stdc++.h>
#include <iostream>
typedef long long int ll;
using namespace std;
class Solution{
  
  public:
        ll solve(ll n){
            ll ans=0;
            if(n == 1)
                return (14 + 6);
            else if(n == 2)
                return (24 + 12);
            else if(n == 3)
                return (33 + 18);
            else if(n == 4)
                return (36 + 24);
            else{
                ans += (n / 4) * 44 ;
                if(n % 4 == 1)
                    return (ans + 32);
                else if(n % 4 ==2)
                    return (ans + 44);
                else if(n % 4 == 3)
                    return (ans + 55);
                else
                    return (ans + 16);
            }
        }
};
int main() {
	// your code goes here
	ll t;
	cin>> t;
	while(t--){
	    ll n;
	    cin >> n;
	    
	    Solution sol_1;
	    std::cout << sol_1.solve(n) << std::endl;
	}
	return 0;
}