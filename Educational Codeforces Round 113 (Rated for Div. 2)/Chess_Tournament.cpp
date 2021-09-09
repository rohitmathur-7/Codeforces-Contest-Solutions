#include<bits/stdc++.h>
#define ll long long int
#define w(t) ll t;cin>>t;while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define scana(arr) for(ll i=0,i<n;i++) cin>>arr[i];
#define printa(arr) for(ll i=0,i<n;i++) cout<<arr[i];
#define vl vector<ll>
#define vpl vector< pair<ll,ll> >
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
                     
//************************
//Important functions
                      
//gcd
/*
ll gcd(ll a,ll b){
    //base case
    if(b==0) return a;
    //rec case
    return gcd(b,a%b);
}
*/
                        
//extended euclid algorithm
/*
void extendedEuclidAlgorithm(ll a,ll b){
    //base case
    if(b==0){
        x=1;y=0;
        GCD=a;
        return;
    }
    //rec case
    extendedEuclidAlgorithm(b,a%b);
    ll cx=y;
    ll cy=x-((a/b)*y);
                    
    x=cx;
    y=cy;
}
*/
                        
//to compute a^b
/*
ll fast_modulo_exponentation(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}
*/
 
//to find multiplicative modulo inverse
/*
void multiplicative_modulo_inverse(ll a,ll m){
    if(gcd(a,m)==1){
        extendedEuclidAlgorithm(a,m);
        //as the func can return -ve value also, so to return +ve value we do (x+m)%m.
        cout<<(x+m)%m<<endl;
    }
    else cout<<
Multiplicative modulo inverse is not possible!
<<endl;
}
*/
 
//prime sieve
/*
void prime_sieve(ll *p){
    for(ll i=3;i<=100000;i+=2) p[i]=1;
 
    for(ll i=3;i<=100000;i+=2){
    if(p[i]==1){
        for(ll j=i*i;j<=100000;j+=i){
            p[j]=0;
        }
        }
        }
    p[2]=1;
    p[1]=0;p[0]=0;
}
*/
//************************

/*
Explanation: 

The 1st observation is that if '2' is present in our string and the (number of '2'<=2) then the answer will always be 'NO' bcz '2' means we have to win atleast once, and suppose the string is "22",
then they both wants to win atleast once which is impossible.
So if we have '2' in our string it should be present atleast 3 times.

Now what want to do is, 
for every s[i] iterate over all others,and create a 2d ans array to mark answers there.
*if s[i] is '1' then if we encounter another '1' then we will mark that as '=' and if we encounter  '2' we will mark '+' for '1' and '-' for '2'.

*if s[i] is '2' and we encounter '1' then we mark it as '-' for '2' and '+' for '1'.
else what we want is to win atleast once, so we will just mark the next '2' as '+' and all other '2' as '='.

This will imply that all 2's get to win atleast once which is all we want.

*/
 
int main(){
 
    w(t){
        ll n;cin>>n;
        string s;cin>>s;
        ll bb=0,last,first;
        f(i,0,n){
            if(s[i]=='2'){
                if(bb==0) first=i;
                bb++;
                last=i;
            }
        }
        if(bb>0){
           if(bb<=2) cout<<"NO"<<endl;
           else{
               cout<<"YES"<<endl;
               char ans[n][n];
               f(i,0,n){
                   f(j,0,n){
                        ans[i][j]='.';
                   }
               }
               f(i,0,n){
                   ll c=0;
                   f(j,0,n){
                       if(i==j){
                           ans[i][j]='X';
                       }
                       else{
                           if(s[i]=='1'){
                               if(s[j]=='1'){
                                    ans[i][j]='=';
                                    ans[j][i]='=';
                               }
                               else{
                                    ans[i][j]='+';
                                    ans[j][i]='-';
                               }
                           }
                           else{
                               if(s[j]=='1'){
                                    ans[i][j]='-';
                                    ans[j][i]='+';
                               }
                               else{
                                   if(i==first){
                                       if(i==j) ans[i][j]=='X';
                                       else{
                                           if(j>i && c==0){
                                               ans[i][j]='+';
                                               ans[j][i]='-';
                                               c++;
                                           }
                                           else{
                                               if(j!=last){
                                                   ans[i][j]='=';
                                                   ans[j][i]='=';
                                               }
                                               else{
                                                   ans[i][j]='-';
                                                   ans[j][i]='+';
                                               }
                                           }
                                       }
                                   }
                                   else{
                                       if(i==j) ans[i][j]='X';
                                       else{
                                           if(j>i && c==0){
                                               ans[i][j]='+';
                                               ans[j][i]='-';
                                               c++;
                                           }
                                           else{
                                               if(ans[i][j]=='.'){
                                                   ans[i][j]='=';
                                                   ans[j][i]='=';
                                               }
                                            }
                                       }
                                   }
                               }
                           }
                       }
                   }
               }
               f(i,0,n){
                   f(j,0,n){
                       cout<<ans[i][j];
                   }
                   cout<<endl;
               }
           } 
        }
        else{
            cout<<"YES"<<endl;
            f(i,0,n){
                f(j,0,n){
                    if(j==i) cout<<"X";
                    else cout<<"=";
                }
                cout<<endl;
            }
        }
    }
     
    return 0;
}