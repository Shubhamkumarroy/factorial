// if n is large and we have to calculate n!%p...if n is large so we should have better than o(n)soln
// p is prime
/*
The largest possible power of a prime pi that divides n is,⌊n/pi⌋ + ⌊n/(pi2)⌋ +  ⌊n/(pi3)⌋ + .....+ 0 
Every integer can be written as multiplication of powers of primes.  So,
  n! = p1k1 * p2k2 * p3k3 * ....
  Where p1, p2, p3, .. are primes and 
        k1, k2, k3, .. are integers greater than or equal to 1.


The idea is to find all primes smaller than n using Sieve of Eratosthenes. For every prime ‘pi‘, 
find the largest power of it that divides n!. Let the largest power be ki. Compute piki % p using modular 
exponentiation. Multiply this with final result under modulo p.
1<=n<=1e5
*/
#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define mia -1e18
#define maa 1e18
#define pii pair<int,int>
using namespace std;
int powerofp(int n,int i){
    int cn=0;
    int x=i;
    while(n>=x){
        cn+=(n/x);
        x*=i;
    }
    return cn;
}
int powermodp(int x,int y,int p){
    if(y==0){
        return 1;
    }
    int ans=powermodp(x,y/2,p);
    ans=(ans*ans)%p;
    return y%2==0?ans:(ans*x)%p;
}
signed main(){
    int tt;
    cin>>tt;
    while(tt--)
    {
                int n,p;
                cin>>n>>p;
                if(n>=p){
                    cout<<0<<endl; // one factor of p comes and it will make all zero
                }
                else{
                    bool prime[n+1];
                    fill(prime,prime+n+1,true);
                    for(int i=2;i<=sqrt(n);i++){
                        if(prime[i]){
                            for(int j=i*i;j<=n;j+=i){
                                prime[j]=false;
                            }
                        }
                    }
                int ans=1;
                for(int i=2;i<=n;i++){
                    if(prime[i]){
                        int x=powerofp(n,i);
                        cout<<x<<" ";
                        ans*=powermodp(i,x,p);
                        ans%=p;
                    }
                }
               cout<<ans<<endl;
                }
               



                
                
    }
}