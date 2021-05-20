
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll a[1005][1005];
int main()
{
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        
        ll j = 1;
        
        for(ll i=0;i<n;i++)
        {
            if (i%2==0)
            for(ll k=0;k<n;k++)
                a[i][k]=j++;
            else
            {
                j+=n-1;
                for(ll k=0;k<n;k++)
                a[i][k]=j--;
                j=a[i][0]+1;
            }
        
        }
 
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }
    }
}   