#include<iostream>
#include<cstring>
/*
遍历做法，数据太水，所以很轻松
struct node{
    int value;
    int lp;
    int rp;
    int pp;
    int size;
};
node arr[200];
int sum[200];
int v[200];
int re=200000000;
using namespace std;
void dfs(int start,int root,int deep){
    if(root==0||v[root]==1){
        return;
    }
    v[root]=1;
    sum[start]+=arr[root].value*deep;
    dfs(start,arr[root].lp,deep+1);
    dfs(start,arr[root].rp,deep+1);
    dfs(start,arr[root].pp,deep+1);
    if(deep==0){
        re=sum[root]>re?re:sum[root];
    }
}
int main(void){
    int n;
    freopen("input.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].value;
        int a,b;
        cin>>a>>b;
        if(a!=0){
            arr[i].lp=a;
            arr[a].pp=i;
        }
        if(b!=0){
            arr[i].rp=b;
            arr[b].pp=i;
        }
    }
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        dfs(i,i,0);
    }
    cout<<re;
    return 0;
}*/
//下面试试dp
//关键点求左右子树的全部权重
//我的思路为通过中序遍历，从下到上开始计算
//这里中序不行，按层序可以，也可以记录值，从目标根节点，分别dfs左右子树，sun遍历过程累加
//缺点为一个节点遍历一遍太麻烦了
//我试试后序遍历
//后序遍历和层序遍历均可，后序通过递归实现，层序通过队列
//目前我对树的理解
//1 树的节点地址可以通过数组存储（与一般地址其实原理一样，通过一个地址{在数组中下标与地址等价
//}找到一片空间）
//2 前序遍历 一般都为从上到下
//而中序遍历  后序遍历为从下到上
//层序遍历都可以，且按层
//3 二叉树的许多应用与左右子树有关
//因此研究左右子树往往比研究整棵树更轻松
#include<queue>
struct node{
    int value;
    int lp;
    int rp;
    int pp;
    int size;
};
node arr[200];
int sum[200];
int v[200];
int re=200000000;
using namespace std;
void precout(int root){
    if(root==0){
        return;
    }
    precout(arr[root].lp);
    precout(arr[root].rp);
    arr[root].size=arr[arr[root].lp].size+arr[arr[root].rp].size+arr[root].value;
}
void dfs(int start,int root,int deep){
    if(root==0||v[root]==1){
        return;
    }
    v[root]=1;
    sum[start]+=arr[root].value*deep;
    dfs(start,arr[root].lp,deep+1);
    dfs(start,arr[root].rp,deep+1);
    dfs(start,arr[root].pp,deep+1);
    if(deep==0){
        re=sum[root]>re?re:sum[root];
    }
}
int main(void){
    int n;
    freopen("input.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].value;
        int a,b;
        cin>>a>>b;
        if(a!=0){
            arr[i].lp=a;
            arr[a].pp=i;
        }
        if(b!=0){
            arr[i].rp=b;
            arr[b].pp=i;
        }
    }
    precout(1);
    dfs(1,1,0);
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int index=q.front();
        q.pop();
        int a=arr[index].rp;
        int b=arr[index].lp;
        if(a!=0){
            q.push(a);
        }
        if(b!=0){
            q.push(b);
        }
        if(index!=1){
            sum[index]=sum[arr[index].pp]-2*arr[index].size+arr[1].size;
            re=sum[index]>re?re:sum[index];
        }
    }
    cout<<re;
    return 0;
}