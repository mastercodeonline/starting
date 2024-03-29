#include<iostream>
#include<string>
#include<queue>
#include<cstring>
#include<stack>
#include<cmath>
//Tarjan用于有向图判环，无向图判环用并查集
//前置知识
//搜索树（进行DFS,且每个点只访问一次搜形成的树）
//1）搜索树不唯一
//2）搜索过程走的边为树边
//3）其余未走的边分为返祖 前向 横叉
//4）四种边可以相互转化（改变搜索顺序）
//5）强联通分量一定存在返祖边
//tarjan算法的过程简述
//入
//1）若边没有访问过
//打上时间戳，继续递归，递归结束后，记录最早节点（与子节点的最早比较），祖先节点一定可以到达儿子节点所能到达的点
//2）若边访问且在栈（节点一定为祖先节点或者兄弟节点，若不在栈，说明已经结算）
//因为此时祖先节点不一定找到最早，所以与时间戳比较即可
//离
//DFS中最先搜索到的强联通分量节点必为跟节点
//根据栈的特性
//根节点必然最后结算，且根节点最早为本身，
//出栈到根节点，结束，
//若果判断不为根节点，无需操作
using namespace std;
/*
struct dat{
    int k;
    dat* next;
};
struct node{
    dat* pa;
    int num;
};
node arr[100005];
int v[100005];
int a[100005];
void dfs(int index){
    v[index]=1;
    dat*pint=arr[index].pa;
    if(pint==NULL){
        return;
    }
    pint=pint->next;
    for(int i=0;i<arr[index].num-1;i++){
        if(v[pint->k]==1){
            //a[pint->k]=a[index]>a[pint->k]?a[index]:a[pint->k];
            pint=pint->next;
            continue;
        }
        a[pint->k]=a[index]>a[pint->k]?a[index]:a[pint->k];
        dfs(pint->k);
        pint=pint->next;
    }
    return;
}*/
//反向建图
//如果后面的优先级高，可以考虑反向，避免循环DFS
/*
int test(void){
    int n,m;
    freopen("input.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>b>>a;
        dat* p=(dat*)malloc(sizeof(dat));
        p->k=b;
        if(arr[a].num==0){
            dat* p1=(dat*)malloc(sizeof(dat));
            dat* p2=(dat*)malloc(sizeof(dat));
            p1->k=-1;
            p2->k=10000000;
            arr[a].pa=p1;
            p1->next=p2;
            arr[a].num++;
        }
        dat*pint=arr[a].pa;
        while(1){
            if(pint->next!=NULL&&b<pint->next->k){
                p->next=pint->next;
                pint->next=p;
                arr[a].num++;
                break;
            }
            pint=pint->next;
        }
    }
    for(int i=n-1;i>=0;i--){ //从最大值开始
        dfs(i+1);
    }
    for(int i=0;i<n;i++){
        cout<<a[i+1]<<' ';
    }
    return 0;
}
*/
//有向图强联通亮算法
struct storenode{
    int data; //数据域
    storenode* next; //指针
};//领结表实现
struct node{
    int data;//数据域
    storenode*store; 
};//图节点
node arr[100005];
int v[10006];
//建树
void creatmap(int a,int b){
    storenode*tmp=(storenode*)malloc(sizeof(storenode));
    tmp->data=b;
    tmp->next=NULL;
    storenode*now=arr[a].store;
    if(now==NULL){
        arr[a].store=tmp;
        return;
    }
    while(now->next!=NULL){
        now=now->next;
    }
    now->next=tmp;
}
//Tarjan算法
//时间戳
int DFN[100005];//DFS的顺序（看为时间顺序）
int LOW[100005];//最早回溯时间点
stack<int>s;//栈储存
int k=1;
int maxk=0;
int unses[100005];
int a[100005];
int find(int k){
    if(unses[k]==k){
        return k;
    }
    return unses[k]=find(unses[k]);
}
void dfstarjan(int index){
    DFN[index]=k;
    LOW[index]=k;
    k++;
    s.push(index);
    storenode*pint=arr[index].store;
    while(pint!=NULL){
        if(DFN[pint->data]==0){
            dfstarjan(pint->data);
        }
        if(LOW[index]>LOW[pint->data]){
            LOW[index]=LOW[pint->data];
        }
        pint=pint->next;
    }
    if(LOW[index]==DFN[index]){
        while(s.top()!=index){
            v[s.top()]=1;
            if(s.top()>maxk){
                v[maxk]=1;
                if(maxk!=0){
                    unses[find(maxk)]=find(s.top());
                }
                maxk=s.top();
                v[maxk]=0;
            }
            unses[find(s.top())]=find(maxk);
            s.pop();
        }
        v[s.top()]=1;
        if(maxk<index){
            v[maxk]=1;
            if(maxk!=0){
                unses[find(maxk)]=find(index);
            }
            maxk=s.top();
            v[maxk]=0;            
        }
        unses[find(s.top())]=find(maxk);
        maxk=-1;
        s.pop();
    }
}
void dfs(int index){
    v[index]=1;
    storenode*pint=arr[index].store;
    while(pint!=NULL){
        if(v[find(pint->data)]==0){
            dfs(find(pint->data));
        }
        a[index]=max(a[index],a[find(pint->data)]);
        pint=pint->next;
    }
}
int test(void){
    int n,m;
    freopen("P3916_2.in","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        unses[i+1]=i+1;
        a[i+1]=i+1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        creatmap(a,b);
    }
    for(int i=0;i<n;i++){
        if(DFN[i+1]==0){
            dfstarjan(i+1);
        }
    }
    for(int i=0;i<n;i++){
        if(v[i+1]==0){
            dfs(i+1);
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[find(i+1)]<<' ';
    }
    return 0;
}
