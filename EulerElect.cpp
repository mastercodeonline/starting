#include<iostream>
#include<algorithm>
#include<cmath>
#include<unordered_set>
#include<cstring>
using namespace std;
//素数筛选
//1 埃氏筛
/*
bool v[100000005];
int re[5770000];
int main(void){
    int n;
    freopen("input.in","r",stdin);
    cin>>n;
    int k=0;
    for(int i=2;i<=n;i++){
        if(v[i]){
            continue;
        }
        re[k]=i;
        k++;
        if(i<sqrt(n)){
            int m=i*i;
            while(m<n){
                v[m]=1;
                m+=i;
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a;
        cin>>a;
        cout<<re[a-1]<<endl;
    }
    return 0;
}*/
//欧拉筛（线性筛）
bool v[20000];
int re[577];
int test(void){
    int n;
    //freopen("input.in","r",stdin);
    cin>>n;
    int k=0;
    for(int i=2;i<=n;i++){
        if(!v[i]){
            re[k]=i;
            k++;
        }
        for(int j=0;j<k;j++){
            if((long long) i*re[j]>n){
                break;
            }
            v[i*re[j]]=1;
            if(i%re[j]==0){
                break;
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a;
        cin>>a;
        cout<<re[a-1]<<endl;
    }
    return 0;
}

