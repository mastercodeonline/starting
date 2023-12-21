#include<map>
#include<set>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
//字典树
//Tire
struct nodeint{
    int x;
    nodeint* next;
};
struct node{
    int x;
    node* p[26];
    nodeint* re;
    int num;
};
void init(node* n){
    memset(n,0,sizeof(node));
}
void find(node* root,char*str,int k){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        int x=str[i]-'a';
        if(root->p[x]==NULL){
            root->p[x]=(node*)malloc(sizeof(node));
            init(root->p[x]);
        }
        root=root->p[x];
    }
    if(root->num==0){
        root->num++;
        root->re=(nodeint*)malloc(sizeof(nodeint));
        root->re->x=k;
        root->re->next=NULL;
    }else{
        nodeint* tmp=root->re;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        if(tmp->x!=k){
            nodeint* buff=(nodeint*)malloc(sizeof(nodeint));
            buff->next=NULL;
            buff->x=k;
            tmp->next=buff;
            root->num++;
        }
    }
}
node* find2(node* root,char*str){
    int n=strlen(str);
    for(int i=0;i<n;i++){
        int x=str[i]-'a';
        if(root->p[x]==NULL){
            root->p[x]=(node*)malloc(sizeof(node));
            init(root->p[x]);
        }
        root=root->p[x];
    }
    return root;
}
int test(void){
    int n;
    freopen("input.in","r",stdin);
    cin>>n;
    node root;
    init(&root);
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            char str[30]="\0";
            cin>>str;
            find(&root,str,i);
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        char str[30]="\0";
        cin>>str;
        node* buff=find2(&root,str);
        nodeint*tmp=buff->re;
        if(tmp==NULL){
            cout<<endl;
            continue;
        }
        while(tmp->next!=NULL){
            cout<<tmp->x<<' ';
            tmp=tmp->next;
        }
        cout<<tmp->x<<' ';
        cout<<endl;
    }
    return 0;
}
