#include<iostream>
//种类并查集
//数据并非在一起，而是知道谁与谁不在一起，且集合数应为确定值
//开n倍数组，记录这种关系，发现不在同一数组
//在后面数组连接，记录排斥关系，
//敌人的敌人是朋友
/*
using namespace std;
struct node{
    int x;
    int y;
    int weight;
};
int cmp(const void*p1,const void*p2){
    return -(((node*)p1)->weight-((node*)p2)->weight);
}
int setk[40005];
node arr[100005];
int find(int x){
    while(1){
        if(x==setk[x]){
            return x;
        }
        x=setk[x];
    }//路径压缩
}
int main(void){
    int n,m;
    freopen("P1525_2.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n*2;i++){
        setk[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[i].x=a;
        arr[i].y=b;
        arr[i].weight=c;
    }
    qsort(arr+1,m,sizeof(node),cmp);
    for(int i=1;i<=m;i++){
        int a=arr[i].x;
        int b=arr[i].y;
        if(find(a)==find(b)){//这里如果要路径压缩的话，要都判断一遍，压缩过程失去了
        //部分回溯关系（不同区间联通性变差，但总会用内部联通的区间）
        //不然就不需要if(find(a)==find(b)||find(a+n)==find(b+n))
            cout<<arr[i].weight;
            return 0;
        }
        setk[find(a+n)]=find(b);
        setk[find(a)]=find(b+n);
    }
    cout<<"0";
    return 0;
}
*/
//三种种类（食物链）
/*
using namespace std;
struct node{
    int a;
    int b;
};
int i;
int s[150005];
//注意一下，找根节点时直接用find()，用数组有可能用的不是压缩后结果
//是关系带来的联通效果，而不是联通带来的关系
//在关押罪犯中两片空间代表不同关系，第一片关系联通意味朋友，第二片关系联通代表敌人
//因为关系只有两种，所以只需要判断一种（find（x）==find(y)||find(x+n)==find(y+n)）
//判两种是因为同关A B不一样
//在食物链中，三片空间代表三种物种（注意不知道具体哪一种），在同一片空间代表同种，在不同空间代表
//有两种关系，吃与被吃；A与B代表吃 A与C代表被吃
//判断一种合法，只需判断另两种是否已经存在
int find(int x){
    if(x==s[x]){
        return x;
    }
    return s[x]=find(s[x]);
}
int main(void){
    int n,m;
    freopen("input.in","r",stdin);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        s[i]=i;
        s[i+n]=i+n;
        s[i+2*n]=i+2*n;
    }
    int re=0;
    for(i=0;i<m;i++){
        int mode;
        cin>>mode;
        int x,y;
        cin>>x>>y;
        if(x>n||y>n){
            re++;
            continue;
        }
        if(mode==1){
            if(find(x)==find(y+n)||find(x)==find(y+2*n)){
                re++;
                continue;
            }
            s[s[x]]=find(y);
            s[find(x+n)]=s[y+n];
            s[find(x+2*n)]=s[y+2*n];
        }else{
            if(find(x)==find(y)||find(x)==find(y+2*n)){
                re++;
                continue;
            }
            s[s[x]]=find(y+n);
            s[find(x+n)]=s[y+2*n];
            s[find(x+2*n)]=s[y];
        }
    }
    cout<<re;
    return 0;
}*/
//带权并查集
//带权重压缩时距离要先记录原根节点，不然改变后无法找到
//权重数组，在合并时进行赋值
/*
using namespace std;
int s[50005];
int d[100005];
int find(int x){
    if(x!=s[x]){
        int u=s[x];
        s[x]=find(s[x]);
        d[x]+=d[u];
    }
    return s[x];
}
int test(void){
    int n,m;
    freopen("P2024_2.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        s[i]=i;
    }
    int re=0;
    for(int i=0;i<m;i++){
        int k,a,b;
        cin>>k>>a>>b;
        if(a>n||b>n){
            re++;
            continue;
        }
        int fa=find(a);
        int fb=find(b);//这里必须要先记录一下，因为合并后find（a)值已经改变了
        if(k==1){
            if(fa==fb&&(d[a]-d[b])%3){
                re++;
            }else if(fa!=fb){//必须没有合并过，才可以合并
                d[fa]=d[b]-d[a];
                s[fa]=fb;
            }
        }else{
            if(fa==fb&&(d[a]-d[b]-1)%3){
                re++;
            }else if(fa!=fb){
                d[fa]=d[b]-d[a]+1;
                s[fa]=fb;
            }
        }
    }
    cout<<re;
    return 0;
}*/