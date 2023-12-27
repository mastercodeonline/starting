#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
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
}
//反向建图
//如果后面的优先级高，可以考虑反向，避免循环DFS
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
//有向图强联通亮算法