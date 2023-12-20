#include<iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
#define M 399967
struct node{
    int a;
    int b;
    int wight;
};
int s[400005];
node arr[200005];
int book[200005];
int find(int x){
    if(x!=s[x]){
        s[x]=find(s[x]);
    }
    return s[x];
}
/*
//离散化做法
//排序
//去重
//得到排序表
//根据排序表替换原来的离散值（low_bond二分查找）
//实现的复杂度NlogN
int main(void){
    int t;
    freopen("P1955_2.in","r",stdin);
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        memset(arr,0,sizeof(arr));
        memset(s,0,sizeof(s));
        memset(book,0,sizeof(book));
        int k1=0;
        int k2=0;
        for(int j=0;j<n;j++){
            int x,y,m;
            cin>>x>>y>>m;
            book[j*2+1]=x;
            book[j*2+2]=y;
            if(m==1){
                arr[k1].a=x;
                arr[k1].b=y;
                k1++;
            }else{
                arr[k2+100000].a=x;
                arr[k2+100000].b=y;
                k2++;
            }
        }
        sort(book+1,book+1+2*n);
        int len=unique(book+1,book+1+2*n)-(book+1);
        for(int k=0;k<k1;k++){
            arr[k].a=lower_bound(book+1,book+1+len,arr[k].a)-(book+1);
            arr[k].b=lower_bound(book+1,book+1+len,arr[k].b)-(book+1);
        }
        for(int k=0;k<k2;k++){
            arr[k+100000].a=lower_bound(book+1,book+1+len,arr[k+100000].a)-(book+1);
            arr[k+100000].b=lower_bound(book+1,book+1+len,arr[k+100000].b)-(book+1);            
        }
        for(int k=0;k<len;k++){
            s[k]=k;
        }
        for(int k=0;k<k1;k++){
            s[find(arr[k].a)]=find(arr[k].b);
        }
        for(int k=100000;k<k2+100000;k++){
            if(find(arr[k].a)==find(arr[k].b)){
                cout<<"NO"<<endl;
                goto a;
            }
        }
        cout<<"YES"<<endl;
        a:int gla=1;
    }
    return 0;
}*/
int test(void){
    int t;
    freopen("P1955_2.in","r",stdin);
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        memset(arr,0,sizeof(arr));
        memset(s,0,sizeof(s));
        int k1=0;
        int k2=0;
        for(int j=0;j<n;j++){
            int x,y,m;
            cin>>x>>y>>m;
            s[x%M]=x%M;
            s[y%M]=y%M;
            if(m==1){
                arr[k1].a=x;
                arr[k1].b=y;
                k1++;
            }else{
                arr[k2+100000].a=x;
                arr[k2+100000].b=y;
                k2++;
            }
        }
        for(int k=0;k<k1;k++){
            s[find((arr[k].a)%M)]=find((arr[k].b)%M);
        } 
        for(int k=100000;k<k2+100000;k++){
            if(find((arr[k].a)%M)==find((arr[k].b)%M)){
                cout<<"NO"<<endl;
                goto a;
            }
        } 
        cout<<"YES"<<endl;
        a:int kkkk=0;      
    }
    return 0;
}