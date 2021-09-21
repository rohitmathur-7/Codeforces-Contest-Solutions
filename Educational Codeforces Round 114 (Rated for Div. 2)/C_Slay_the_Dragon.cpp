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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
    vl arr;
    ll sum=0;
    f(i,0,n){
        ll d;cin>>d;
        arr.pb(d);
        sum+=d;
    }
    ll tsum=sum;
    sort(arr.begin(),arr.end());
    ll mx=arr[n-1];
    ll m;cin>>m;        
    ll ans=0;
    f(i,0,m){
        ll x,y;
        cin>>x>>y;
        if(x>mx){
            ans+=(x-mx);
            tsum-=mx;
            if(y>tsum) ans+=(y-tsum);
            cout<<ans<<endl;
            ans=0;
            tsum=sum;
        }
        else{
            ll pos;
            pos=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
            //we can include value at pos or not
            //include
            ll ans1,ans2=LLONG_MAX;
            tsum-=arr[pos];
            if(y>tsum) ans1=y-tsum;
            else ans1=0;
            tsum=sum;
            //exclude
            if(pos-1>=0){
                ans2=x-arr[pos-1];
                tsum-=arr[pos-1];
                if(y>tsum) ans2+=(y-tsum);
            }
            ans=min(ans1,ans2);    
            cout<<ans<<endl;
            ans=0;
            tsum=sum;
        }
    }
     
    return 0;
}