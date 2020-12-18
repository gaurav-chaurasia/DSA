/*spiral*/
#include <bits/stdc++.h>
 
using namespace std;

vector <vector<int>> getSpiralMatrix(int n) {
    int t=0,l=0,r=n-1,b=n-1;
    int d=0,count=1;
    vector<vector<int> >a(n,vector<int>(n));
    while(t<=b&&l<=r){
        if(d==0){
            for(int i=l;i<=r;i++){
                a[t][i]=count;
                count++;
            }
            d=1;
            t++;
        }
        else if(d==1){
            for(int i=t;i<=b;i++){
                a[i][r]=count;
                count++;
            }
            d=2;
            r--;
        }
        else if(d==2){
            for(int i=r;i>=l;i--){
                a[b][i]=count;
                count++;
            }
            d=3;
            b--;
        }
        else if(d==3){
            for(int i=b;i>=t;i--){
                a[i][l]=count;
                count++;
            }
            d=0;
            l++;
        }
    }
    return a;
}

void solve(){
    int n, col, row;
    cin >> n;
    vector <vector <int>> vec = getSpiralMatrix(n);
    col = vec.at(0).size();
    row = vec.size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << vec.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int t{0};
    cin >> t;
    while (t--){
       solve();
    }   
    return 0;
}
