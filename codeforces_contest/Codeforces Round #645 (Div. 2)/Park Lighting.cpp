// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int solve() {
    int n, m;
    cin >> n >> m;
    return (n*m + 1)/2;
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       cout << solve() << endl;
    }   
    return 0;
}

