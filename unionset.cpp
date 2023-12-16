#include<iostream>
//并查集的实现
//1 并查集的数据特点
//1）数据之间只是集合关系，没有权值
//2）不考虑数据的具体查询，只需知道元素是否在集合中（两个元素是否在同一个元素）
//2实现方式
//1）树的方式实现（树特点：子树数目不知道，只需回溯根节点，而不考虑深搜）
//2）根据树的特点，所以不要子树节点，而用根树节点，开始根节点为本身
//3）三种方式（按总复杂度排序）（需要find union //connect）
//1））建立节点数组，记录回溯根节点，合并是遍历数组改节点（union复杂度变大）
//2））逐层回溯找根节点，再连接根节点（find的复杂度变大）
//3））记录每棵树的权值（此为元素个数），权值大的树做新树的根，（由于一开始建立，所以可以知道
//元素越多，深度必大），只有深度相同时新树的深度增加
//这里采用三种方式分别实现
using namespace std;
//方法1 103ms
//int arr[5005];
/*
int main(void){
    int n,m,p;
    freopen("input.in","r",stdin);
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        if(arr[b]==arr[a]){
            continue;
        }
        int x=arr[b];//这里提前记录一下值，以后可能被修改
        for(int j=1;j<=n;j++){
            if(arr[j]==x){
                arr[j]=arr[a];
            }
        }
    }
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        if(arr[a]==arr[b]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}*/
//方法2（简化合并，复杂查找）73ms
/*
int find(int x){
    while(1){
        if(arr[x]==x){
            return x;
        }
        x=arr[x];
    }
}
int main(void){
    int n,m,p;
    freopen("input.in","r",stdin);
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)){
            continue;
        }
        int x=find(b);//这里提前记录一下值，以后可能被修改
        int y=find(a);
        arr[x]=y;
    }
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}*/
//方法3（加权值）54ms
//
struct node{
    int pre;
    int size;
};
node arr[5005];
int find(int x){
    while(1){
        if(x==arr[x].pre){
            return x;
        }
        x=arr[x].pre;
    }
}
void unionset(int x,int y){
    int a=find(x);
    int b=find(y);
    if(arr[a].size>arr[b].size){
        arr[b].pre=a;
        arr[a].size+=arr[b].size;
    }else{
        arr[a].pre=b;
        arr[b].size+=arr[a].size;
    }
}
int test(void){
    int n,m,p;
    freopen("input.in","r",stdin);
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        arr[i].pre=i;
        arr[i].size=1;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)){
            continue;
        }
        unionset(a,b);
    }
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}

