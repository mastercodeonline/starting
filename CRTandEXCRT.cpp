#include<iostream>
typedef long long ll;
using namespace std;
//中国剩余定理
//CRT
//若存在不互质的数
//可以证明：两种要么矛盾 要么可以写为一个方程（m=a*b/gcd(a,b)）;
//所有两个方程可以合并为一个方程

ll m[100005];
ll r[100005];
long long exgcd(ll a,ll b,ll&x,ll&y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll d=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-a/b*y1;
    return d;
}
ll CRT(ll m[],ll r[],int n){
    ll M=1;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(m[i]==-1){
            continue;
        }
        M*=m[i];
    }
    for(int i=0;i<n;i++){
        if(m[i]==-1||m[i]==1){
            continue;
        }
        ll c=M/m[i];
        ll x,y;
        exgcd(c,m[i],x,y);//通解不是倍数关系，必须控制正负
        ans=(ans+(r[i]*x*c%M))%M;
    }
    return (ans%M+M)%M;
}
ll mul(ll a,ll b,ll mod){
    if(b<0){
        b=(b%mod+mod)%mod;
    }
    ll re=0;
    while(b>0){
        if(b&1){
            re=(re+a)%mod;
        }
        b>>=1;
        a=(a+a)%mod;
    }
    return re;
}
ll excrt(ll m[],ll r[], int n){
    ll m1=m[0];
    ll r1=r[0];
    ll x,y,d;
    for(int i=1;i<n;i++){
        ll b=r[i]-r1;
        b=(b%m[i]+m[i])%m[i];
        d=exgcd(m1,m[i],x,y);
        ll p=m[i]/d;
        if(b%d){
            return -1;
        }
        x=mul(x,b/d,m[i]/d);
        r1=x*m1+r1;
        m1=m1*p;
        r1=(r1%m1+m1)%m1;
    }
    return (r1%m1+m1)%m1;
}
bool v[1000005];
ll prim[150005];
ll EulerElect(ll n){
    ll k=0;
    for(ll i=2;i<=n;i++){
        if(!v[i]){
            prim[k]=i;
            k++;
        }
        for(ll j=0;j<k;j++){
            if(prim[j]*i>n){
                break;
            }
            v[prim[j]*i]=1;
            if(i%prim[j]==0){
                break;
            }
        }
    }
    return k;
}
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
int main(void){
    int n;
    freopen("P4777_13.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i]>>r[i];
    }
    ll ans=excrt(m,r,n);
    cout<<ans;
    return 0;
}
/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
ll M,x,y,n;
ll ans,a[110000],b[110000];
inline ll exgcd(ll p,ll q,ll &x,ll &y){
    if(!q){
        x=1;
        y=0;
        return p;
    }
    ll g=exgcd(q,p%q,y,x);
    y-=(p/q)*x;
    return g;
}
inline ll mul(ll a,ll b,ll c){
	ll res=0;
	while(b>0){
		if(b&1){
			res=((res+a))%c;
		}
		a=(a+a)%c;
		b>>=1;
	}
	return (res%c+c)%c;
}
ll excrt(){
    M=b[1];
    ans=a[1];
    for(ll i=2;i<=n;++i){
        ll c=((a[i]-ans)%b[i]+b[i])%b[i];
        ll g=exgcd(M,b[i],x,y);
        ll p=b[i]/g;
        x=mul(x,c/g,p);
        ans+=x*M;
        M*=p;
        ans=(ans%M+M)%M;
    }
    return ans;
}
int main(){
    freopen("P4777_13.in","r",stdin);
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i){
        scanf("%lld%lld",&b[i],&a[i]);
    }
    printf("%lld\n",excrt());
    return 0;
}*/
