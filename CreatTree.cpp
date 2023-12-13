#include<iostream>
#include<cstring>
using namespace std;
struct node{
    char id;
    node* left;
    node* right;
};
node arr[50];
int k=0;
string a;
string b;
int n=0;
int num=0;

void dfs(node* root){
    if(root==NULL){
        return;
    }
    dfs(root->left);
    dfs(root->right);
    cout<<root->id;
}
void dfscreat(string a,string b){
    if(a.length()<=1){
        return;
    }
    for(int i=0;i<a.length();i++){
        if(a[i]==b[0]){
            if(i==0){
                string a1=a.substr(1);
                string b1=b.substr(1);
                arr[b[0]-'A'].right=&(arr[b1[0]-'A']);
                dfscreat(a1,b1);
            }else if(i==a.length()-1){
                string a1=a.erase(i);
                string b1=b.substr(1);
                arr[b[0]-'A'].left=&(arr[b1[0]-'A']);
                dfscreat(a1,b1);
            }else{
                string a2=a.substr(i+1);
                string a1=a.substr(0,i);
                string b1=b.substr(1,i);
                string b2=b.substr(1+i);
                arr[b[0]-'A'].left=&(arr[b1[0]-'A']);
                arr[b[0]-'A'].right=&(arr[b2[0]-'A']);
                dfscreat(a1,b1);
                dfscreat(a2,b2);
            }
        }
    }
}
int test(void){
    memset(arr,0,sizeof(arr));
    freopen("input.in","r",stdin);
    cin>>a>>b;
    num=a.length();
    for(int i=0;i<27;i++){
        arr[i].id=i+'A';
    }
    int x=b[0]-'A';
    dfscreat(a,b);
    dfs(&(arr[x]));
    return 0;
}