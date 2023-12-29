#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
//判断和求解欧拉回路
int in[27];
int out[27];
struct node{
    string data;
    node*next;
};
int cmp(string a,string b){
    return a>b;
}
node* arc[27];
string re[1002];
string s[1002];
int v[26][100];
int n;
//dfs算法实现欧拉回路求解
void dfs(int index,int deep){
    if(deep==n){
        for(int i=0;i<n-1;i++){
            cout<<re[i]<<'.';
        }
        cout<<re[n-1];
        exit(0);
    }
    node*tmp=arc[index];
    int k=0;
    while(tmp!=NULL){
        if(v[index][k]==1){
            tmp=tmp->next;
            k++;
            continue;
        }
        int x=tmp->data[tmp->data.length()-1]-'a';
        re[deep]=tmp->data;
        v[index][k]=1;
        dfs(x,deep+1);
        v[index][k]=0;
        tmp=tmp->next;
        k++;
    }
}
//弗莱尔算法————求边需要额外操作
stack<int> S;
void dfs_fleuer(int x){
    S.push(x);
    node*now=arc[x];
    int k=0;
    while(now!=NULL){
        if(v[x][k]==1){
            k++;
            now=now->next;
            continue;
        }
        int y=now->data[now->data.length()-1]-'a';
        v[x][k]=1;
        dfs_fleuer(y);
        break;
    }
}
int reint[1000];
void feluer(int x){
    S.push(x);
    int deep=0;
    while(!S.empty()){
        int x=S.top();
        node*now=arc[x];
        int flag=0;
        int k=0;
        while(now!=NULL){
            if(v[x][k]==1){
                k++;
                now=now->next;
                continue;
            }
            flag=1;
            break;
        }
        if(flag==1){
            S.pop();
            dfs_fleuer(x);
        }else{
            reint[deep++]=x;
            S.pop();
        }
    }
}
int test(void){
    freopen("input.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n,cmp);
    string a;
    for(int i=0;i<n;i++){
        a=s[i];
        node* tmp=new node;
        tmp->data=a;
        int x,y;
        x=a[0]-'a';
        y=a[a.length()-1]-'a';
        in[y]++;
        out[x]++;
        tmp->next=arc[x];
        arc[x]=tmp;
    }
    int start=0;
    int end=0;
    for(int i=0;i<26;i++){
        if(in[i]!=out[i]){
            if(out[i]-in[i]==1){
                start=i;
            }else if(out[i]-in[i]!=-1){
                cout<<"***";
                return 0;
            }
            end++;
        }
    }
    if(end!=2&&end!=0){
        cout<<"***";
        return 0;
    }
    if(end==0){
        for(int i=0;i<0;i++){
            if(out[i]!=0){
                feluer(i);
            }
        }
    }else{
        feluer(start);
    }
    for(int i=0;i<=n;i++){
        char a=reint[i]+'a';
        cout<<a<<'.';
    }
    cout<<"***";
    return 0;
}
/*
#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
const int maxm = 26;
const int maxn = 1010;
int exist[maxm],set[maxm];
int find(int x){
    return set[x]==x ? x : set[x] = find(set[x]);
}
struct edge{
    int s,t,key;
    bool operator < (const edge &a){
        if(s != a.s) return s < a.s;
        return key < a.key;
    }
}e[2*maxn]; int p1,p2;
void add(int a,int b,int k){
    e[++p1].s=a,e[p1].t=b;
}
string st[maxn],ans[maxn];
int n,rudu[maxm],chudu[maxm],head=-1,vis[maxn],ptr,flag;
bool judge(){
    for(int i = 0;i < maxm;i++) set[i] = i;
    for(int i = 1;i <= p1;i++){
        int a = e[i].s,b = e[i].t;
        int fa = find(a),fb = find(b);
        if(fa != fb) set[fa] = fb;
    }
    int cnt = 0;
    for(int i = 0;i < maxm;i++)
        if(exist[i] && set[i]==i)
            cnt++;
    if(cnt != 1) return false;
    return true;
}
void dfs(int now){
    for(int i = 1;i <= n;i++)
        if(st[i][0]-'a'==now && !vis[i]){
            vis[i] = 1;
            dfs(st[i][st[i].length()-1]-'a');
            ans[++ptr] = st[i];
        }
}
int main(){
    freopen("input.in","r",stdin);
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>st[i];
    sort(st+1,st+1+n);
    for(int i = 1;i <= n;i++){
        int a = st[i][0]-'a',b = st[i][st[i].length()-1]-'a';
        if(!exist[a]) exist[a]=1; if(!exist[b]) exist[b] = 1;
        add(a,b,0); add(b,a,0);
        rudu[b]++,chudu[a]++;
    }
    if(!judge()){
        cout<<"***"; return 0;
    }
    int cnt = 0;
    for(int i = 0;i < maxm;i++){
        if(abs(chudu[i]-rudu[i]) >= 1){
            cnt++;
            if(abs(chudu[i]-rudu[i]) > 1){
                cout<<"***"; return 0;
            }else if(chudu[i]-rudu[i]==1 && head==-1) head = i;
        }
    }
//    cout<<cnt<<" "<<head<<endl;
    if(cnt != 0 && cnt != 2){
        cout<<"***"; return 0;
    }else if(cnt == 2) dfs(head);
    else for(int i = 0;i < maxm;i++) if(exist[i]) dfs(i);
    for(int i = ptr;i >= 1;i--){
        cout<<ans[i];
        if(i > 1) cout<<".";
    } 
    return 0;
}*/