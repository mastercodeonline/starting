#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<cmath>
typedef long long ll;
using namespace std;
int num[2005];
int sum=0;
int maxn=20000;
int arr[1005];
int deque[2005];
int sizedp=0;
int h=0,t=0;
int min(int a,int b){
    return a>b?b:a;
}
void tpush(int x){
    deque[t]=x;
    if(t==maxn){
        t=0;
    }else{
        t++;
    }
    sizedp++;
}
void hpush(int x){
    deque[h]=x;
    if(h==0){
        h=maxn;
    }else{
        h--;
    }
    sizedp++;
}
void tpop(void){
    if(t==0){
        t=maxn;
    }else{
        t--;
    }
    sizedp--;
}
void hpop(void){
    if(h==maxn){
        h=0;
    }else{
        h++;
    }
    sizedp--;
}
int test(void){
    int n;
    freopen("input.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
    }
    int l=1,r;
    tpush(0);
    int ans=-99999999;
    for(int r=1;r<=n;r++){
        if(arr[r]-deque[h]>ans){
            ans=arr[r]-deque[h];
        }
        while(arr[r]<=deque[t-1]&&sizedp>0){
            tpop();
        }
        tpush(arr[r]);
    }
    cout<<ans;
    return 0;
}
