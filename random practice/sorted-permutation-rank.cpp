#include <iostream>
using namespace std;
#define mod 1000003;

int factorial(int n) {
    if(n==0) 
        return 1 ; 
    else 
        return (n*factorial(n-1)) %mod;
}
int findRank(string A) {
    string s=A ;
    int ans =0;
    int n=s.length();
    for(int i=0;i<n-1;i++) {
        int count=0;
        for(int j=i+1;j<n;j++) { // calculating number of char less than i'th char
            if(s[j]<s[i])
                count++; // count of small char
        }   
        ans+=((count*factorial( n-(i+1) )))%mod; 
    }
    return (ans+1)%mod;
} 
int main () {
    string str;
    cin >> str;
    cout << findRank(str) << endl;
}