// if n is smaller number then we can simply calculate factorial.
#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define mia -1e18
#define maa 1e18
#define pii pair<int,int>
using namespace std;
int fact(int n){
    if(n==0 ||n==1){
        return 1;
    }
    return n*fact(n-1);
}
signed main(){
    int tt;
    cin>>tt;
    while(tt--)
    {
                int n;
                cin>>n;
                cout<<fact(n)<<endl;
                
    }
}