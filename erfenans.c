#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//二分答案 答案具有一定范围，也具有一定单调性，方便检验答案正确，可以二分查找答案，而非元素
int arr[100006]={0};
int judge(int mid,int n){//判断函数，不同题目函数不同，关键为快速判断是否可行
    int num=0;
    int sum=arr[0];
    for(int i=0;i<n;i++){
        if(sum<mid){
            sum+=arr[i+1];
            num++;
        }else{
            sum=arr[i+1];
        }
    }
    return num;
}
int Test(void){
    int n,m,l;
    scanf("%d%d%d",&l,&n,&m);
    int maxm=0;
    int minm=2000000000;
    int min=0;
    for(int i=0;i<n;i++){
        int n2;
        scanf("%d",&n2);
        arr[i]=n2-min;
        min=n2;
        if(arr[i]>maxm){
            maxm=arr[i];
        }
        if(arr[i]<minm){
            minm=arr[i];
        }
        if(i==n-1){
            arr[n]=l-n2;
        }
    }
    maxm=l;
    int ans;
    int mid=(maxm+minm)/2;
    while(maxm>=minm){
        if(judge(mid,n+1)>m){
            maxm=mid-1;
            mid=(maxm+minm)/2;
        }else{
            ans=mid;
            minm=mid+1;
            mid=(maxm+minm)/2;
        } 
    }
    printf("%d",ans);
}