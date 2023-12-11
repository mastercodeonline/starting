#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//freopen("input.in","r",stdin);
//基本想法
//问题所在
//还是不知道如何避免查询
//这里有一种方法实现
//数组加链表
//实现方式
//先加元素（这里已经给出了元素），这里用数组存储元素，数组作为一个查询表（建立元素与数组下标的映射关系）
//可以用哈希，不过这里用不到，所以这里比较简单（虽然我没想到），元素建立前后节点
//实现顺序排放
/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int mx=1e5+10;
int n,m;
struct T{
    int l,r;        //每个同学的“左右手” ！！！！！！！！！！！！！！！！！！！！！！！！
	int d;          //表示同学是否输出   ！！！！！！！！！！！！！！！！！！！！！！！！
}t[mx]={0};
void add(int i,int k,int f)       //新增同学 
{
    if(f==1)         //左 
    {
        t[k].r=t[i].r;
        t[k].l=i; 
        t[i].r=k;
        t[t[k].r].l=k;
    }
    else             //右 
    {
        t[k].r=i;
        t[k].l=t[i].l;
        t[i].l=k;
        t[t[k].l].r=k;
    }
}
int main()
{
    int x,k,f;
    cin>>n;
    t[0].r=0,t[0].l=0;
    add(0,1,1);
    for (int i=2;i<=n;i++)
    {
        cin>>x>>f;
        add(x,i,f);
    }
    cin>>m;
    while(m--)
    {
        cin>>x;
        t[x].d=1;         //将该同学标记为不输出 
    }
    for (int i=t[0].r;i;i=t[i].r)
    {
        if (t[i].d==0)    //输出未标记的 
          cout<<i<<" ";
    }
    return 0;
}
*/
int arr[100005];
int d[100005];
int test(void){
    int n;
    freopen("input.in","r",stdin);
    scanf("%d",&n);
    arr[0]=1;
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        for(int j=0;j<i;j++){
            if(arr[j]==a){
                if(b==0){
                    memmove(arr+j+1,arr+j,(i-j)*sizeof(int));
                    arr[j]=i+1;
                    break;
                }else{
                    memmove(arr+j+2,arr+j+1,(i-j-1)*sizeof(int));
                    arr[j+1]=i+1;
                    break;
                }
            }
        }
    }
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        int a;
        scanf("%d",&a);
        d[a]=-1;
    }
    for(int i=0;i<n;i++){
        if(d[arr[i]]==-1){
            continue;
        }
        printf("%d ",arr[i]);
    }
    return 0;
}