#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int arr[50005];
int f[50005][16];
int f2[50005][16];
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a>b?b:a;
}
int cmp(const void*p1,const void*p2){
    return ((int*)p1)[0]-((int*)p2)[0];
}
int highbit(int x){
    x|=(x>>1);
    x|=(x>>2);
    x|=(x>>4);
    x|=(x>>8);
    x|=(x>>16);
    return (x+1)>>1;
}
int highnum(int x){
    int k=-1;
    while(x){
        x>>=1;
        k++;
    }
    return k;
}
int getre(int l,int r){
    int k=highnum(r-l+1);
    return max(f[l][k],f[r-(1<<k)+1][k])-min(f2[l][k],f2[r+1-(1<<k)][k]);
}
int yest(void){
    int n,m;
   // freopen("input.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        f[i][0]=arr[i];
        f2[i][0]=arr[i];
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int j=1;j<=15;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        cout<<getre(l,r)<<endl;
    }
    return 0;
}
