
//一维前缀
/*
int arr[100005];
void bulitsum(int arr[],int n){
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
    }
}
int getsum(int arr[],int a,int b){
    return arr[a]-arr[b-1];
}
int main(void){
    int n,m;
    freopen("input.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    bulitsum(arr,n);
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cout<<getsum(arr,b,a)<<endl;
    }
    return 0;
}*/
//二维前缀
/*
#include<iostream>
using namespace std;
int arr[125][125];
void bulitsum(int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr[i][j]=arr[i-1][j]+arr[i][j-1]+arr[i][j]-arr[i-1][j-1];
        }
    }
}
int getsum(int x1,int y1,int x2,int y2){
    return arr[x1][y1]-arr[x1][y2-1]-arr[x2-1][y1]+arr[x2-1][y2-1];
}
int ma(int a,int b){
    return a>b?a:b;
}
int dp[125][125];
int main(void){
    int n;
    freopen("input.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    bulitsum(n,n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=ma(dp[i][j-1],dp[i-1][j]);
            for(int k1=1;k1<i;k1++){
                for(int k2=1;k2<j;k2++){
                    dp[i][j]=ma(dp[i][j],getsum(i,j,k1,k2));
                }
            }
        }
    }
    cout<<dp[n][n];
    return 0;
}*/
//一维差分
/*
#include<iostream>
typedef long long ll;
using namespace std;
ll arr[5000005];
void bulitdiff(ll arr[],int n){
    for(int i=n;i>=1;i--){
        arr[i]=arr[i]-arr[i-1];
    }
}
void backdiff(ll arr[],int n){
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
    }
}
void setdiff(ll arr[],int l,int r,ll value){
    arr[l]+=value;
    arr[r+1]-=value;
}
int main(void){
    int n,m;
    freopen("input.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    bulitdiff(arr,n);
    for(int i=0;i<m;i++){
        int l,r;
        ll v;
        cin>>l>>r>>v;
        setdiff(arr,l,r,v);
    }
    backdiff(arr,n);
    ll min=99999999999999;
    for(int i=1;i<=n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<min;
    return 0;
}*/
#include<iostream>
using namespace std;
int arr[1005][1005];
void add(int lx,int ly,int rx,int ry,int value){
    arr[lx][ly]+=value;
    arr[rx+1][ry+1]+=value;
    arr[lx][ry+1]-=value;
    arr[rx+1][ly]-=value;
}
void back(int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr[i][j]+=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
        }
    }
}
int test(void){
    int n,m;
    freopen("input.in","r",stdin);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        add(a,b,c,d,1);
    }
    back(n,n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
//昊昊爱运动
//如果求k天的最多运动用滑动窗口
//如果不限询问，可以前缀和（每种运动分别记录），也可以预处理
