#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
//思路没有太大问题，需要只是快速冥和逆元
//求逆元时，由于mod数一般为质数
//有k*mod不存在逆元，需要特殊对待
//具体情况特判
//求逆元的两种方法
//费马小定理（快速幂）
//拓展欧拉定理+裴蜀定理
long long final=0;
bool v[10005];
ll prim[10005];
int re[100][2];
long long quickpow(ll x,ll n){
    long long re=1;
    long long time=x;
    while(n){
        if(n&1==1){
            re=(time%9901)*(re%9901);
            re%=9901;
        }
        n=n>>1;
        time=((time%9901)*(time%9901))%9901;
    }
    return re;
}
//拓展欧拉算法
int euler_exgcd(int a,int b,int&x,int&y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=euler_exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-a/b*y1;
    return d;
}
int test(void){
    ll a,b;
    freopen("input.in","r",stdin);
    cin>>a>>b;
    int k=0;
    for(int i=2;i<10005;i++){
        if(!v[i]){
            prim[k]=i;
            k++;
        }
        for(int j=0;j<k;j++){
            if(i*prim[j]>10005){
                break;
            }
            v[i*prim[j]]=1;
            if(i%prim[j]==0){
                break;
            }
        }
    }
    int c=0;
    for(int i=0;i<k&&prim[i]*prim[i]<=a;i++){
        int n=0;
        while(a%prim[i]==0){
            n++;
            a/=prim[i];
        }
        if(n!=0){
            re[c][0]=prim[i];
            re[c][1]=n;
            c++;
        }
    }
    if(a!=1){
        re[c][0]=a;
        re[c][1]=1;
        c++;
    }
    ll s=1;
    for(int i=0;i<c;i++){
        if(re[i][0]==2){
            s=((s%9901)*((quickpow(re[i][0],re[i][1]*b+1)-1)%9901+9901))%9901;
        }else{
            if(re[i][0]%9901==1){
                s=(s*(1+re[i][1]))%9901;
                continue;
            }
            int x,y;
            euler_exgcd(re[i][0]-1,9901,x,y);
            x=(x%9901+9901)%9901;
            s=(s*((quickpow(re[i][0],re[i][1]*b+1)-1)%9901+9901)*(x%9901))%9901;
        }
    }
    cout<<s;
    return 0;
}
