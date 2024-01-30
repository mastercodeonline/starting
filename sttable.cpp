#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int arr[50005];
int f[50005][16];
int f2[50005][16];
//1 可重复元素的倍增
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
//2 不可重复但可拆分元素的倍增（比如区间和）
#include<bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;
const int MAXN=1e5+10;
int n,q,d[MAXN],c[MAXN],r,v,b[MAXN],nxt[MAXN][20],sum[MAXN][20];
stack <int> stk;

void find_max(){
	for(ri i=1;i<=n;i++){
		while(stk.empty()==0&&d[i]>d[stk.top()]){
			nxt[stk.top()][0]=i;
			sum[stk.top()][0]=c[i];
			stk.pop();
		}
		stk.push(i);
	}
	while(stk.empty()==0){
		nxt[stk.top()][0]=0;
		stk.pop();
	}
}

void pre_rmq(){
	for(ri j=1;(1<<j)<=n;j++){
		for(ri i=1;i+(1<<j)<=n;i++){
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
			sum[i][j]=sum[i][j-1]+sum[nxt[i][j-1]][j-1];
		}
	}
}

int query(int r,int val){
	if(c[r]>=val){
		return r;
	}
	val-=c[r];
	for(ri i=18;i>=0;i--){
		if(nxt[r][i]!=0&&val>sum[r][i]){
			val-=sum[r][i];
			r=nxt[r][i];
		}
	}
	return nxt[r][0];
}

int main() {
	scanf("%d%d",&n,&q);
	for(ri i=1;i<=n;i++)scanf("%d%d",&d[i],&c[i]);
	memset(sum,0x3f,sizeof(sum));
	find_max();
	pre_rmq();
	for(ri i=1;i<=q;i++){
		scanf("%d%d",&r,&v);
		printf("%d\n",query(r,v));
	}
	return 0;
}
