/*Wilson’s theorem states that a natural number p > 1 is a prime number if and only if 

    (p - 1) ! ≡ -1   mod p 
OR  (p - 1) ! ≡  (p-1) mod p 
Note that n! % p is 0 if n >= p. This method is mainly useful when p is close to input number n. For example (25! % 29). From Wilson’s theorem, we know that 28! is -1. So we basically need to find [ (-1) * inverse(28, 29) * inverse(27, 29) * inverse(26) ] % 29. 
The inverse function inverse(x, p) returns inverse of x under modulo p (See this for details). 
    if(n>=p) then factorial will be 0 
    if(p>n) the a/c to wilson theorem (p-1)!=(p-1)%p;
    (p-1)*(p-2)*(p-3)...(n)!=(p-1).
    n!=(p-1)*modulainverse(p-1)*modulainverse(p-2)*...modulainverse(n+1);
    calculate modula inverse using fermetts theorem i.e a^-1=a^(M-2)% M;
    time O((p-n)*Logn) this method is best when p and n are near.

    // method to find n!%p in (p-n) time.
*/
#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define mia -1e18
#define maa 1e18
#define pii pair<int,int>
using namespace std;
int modulainverse(int a,int n,int p){
    if(n==0){
        return 1;
    }
    int ans=modulainverse(a,n/2,p);
    ans=(ans*ans)%p;
    return (n%2==0)?ans:(ans*a)%p;
}
int fact(int n,int p){
    int ans=p-1;// ac to wilson theorm
    for(int i=p-1;i>n;i--){
        ans=(ans*modulainverse(i,p-2,p))%p;
    }
    return ans;
}
signed main(){
    int tt;
    cin>>tt;
    while(tt--)
    {
                int n,p;
                cin>>n>>p;
                if(n>=p){
                    cout<<0<<endl;
                }
                else{
                    cout<<fact(n,p);
                }
                
    }
}
