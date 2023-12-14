#include<iostream>
using namespace std;
/*
BST（Binary Search Tree），二叉搜索树，又叫二叉排序树

是一棵空树或具有以下几种性质的树:

1若左子树不空，则左子树上所有结点的值均小于它的根结点的值

2若右子树不空，则右子树上所有结点的值均大于它的根结点的值

3左、右子树也分别为二叉排序树

4没有权值相等的结点。!!!!!不能相等

看到第4条，我们会有一个疑问，在数据中遇到多个相等的数该怎么办呢，显然我们可以多加一个计数器，就是当前这个值出现了几遍。
*/
//下面是我写的，有问题，在于加了重复元素
/*
struct node{
    int v;
    node* left;
    node* right;
};
void insert(node*root,int value){
    node*tmp=(node*)malloc(sizeof(node));
    tmp->v=value;
    tmp->left=NULL;
    tmp->right=NULL;
    node*now=root;
    while(now!=NULL){
        if(value>=now->v){
            if(now->right==NULL){
                now->right=tmp;
                break;
            }else{
                now=now->right;
            }
        }else{
            if(now->left==NULL){
                now->left=tmp;
                break;
            }else{
                now=now->left;
            }
        }
    }
}
int findback(node*root,int value){
    node*now=root;
    int flag=0;
    while(now->v!=value){
        if(now->v>value){
            if(now->left->v==value){
                flag=1;
                break;
            }
            now=now->left;
        }else{
            now=now->right;
        }
    }
    if(flag==1&&now->left->right==NULL){
        return now->v;
    }else if(flag==1){
        now=now->left;
    }
    while(now->v==value){
        now=now->right;
    }
    return now->v;
}
int findfront(node*root,int value){
    node*now=root;
    int flag=0;
    while(now!=NULL&&now->v!=value){
        if(now->v>value){
            now=now->left;
        }else{
            if(now->right->v==value){
                flag=1;
                break;
            }
            now=now->right;
        }
    }
    if(flag==1&&now->right->left==NULL){
        return now->v;
    }else if(flag==1){
        now=now->right;
    }
    while(now!=NULL&&now->v==value){
        now=now->left;
    }   
    return now->v;
}
int flag=0;
int rankk=-1;
int finanl=-1;
void dfs(node*root,int value){
    if(root==NULL){
        return;
    }
    if(flag==1){
        return;
    }
    dfs(root->left,value);
    rankk++;
    if(root->v==value){
        flag=1;
        finanl=rankk;
    }
    dfs(root->right,value);
}
int findrank(node*root,int value){
    flag=0;
    rankk=-1;
    dfs(root,value);
    return finanl;
}
int re=-1;
int nrank=-1;
void dfsrank(node*root,int des){
    if(root==NULL){
        return;
    }
    if(flag==1){
        return;
    }
    dfsrank(root->left,des);
    nrank++;
    if(nrank==des){
        flag=1;
        re=root->v;
    }
    dfsrank(root->right,des);
}
int findrankvalue(node*root,int rank){
    flag=0;
    re=-1;
    nrank=-1;
    dfsrank(root,rank);
    return re;
}
int main(void){
    int n;
    freopen("input.in","r",stdin);
    cin>>n;
    node root;
    root.right=NULL;
    root.v=0x7fffffff;
    node deep;
    deep.left=NULL;
    deep.right=NULL;
    deep.v=-0x7fffffff;
    root.left=&deep;
    for(int i=0;i<n;i++){
        int m,x;
        cin>>m>>x;
        if(m==1){
            int ans=findrank(&root,x);
            cout<<ans<<endl;
        }else if(m==2){
            int ans=findrankvalue(&root,x);
            cout<<ans<<endl;
        }else if(m==3){
             int ans=findfront(&root,x);
             cout<<ans<<endl;
        }else if(m==4){
             int ans=findback(&root,x);
             cout<<ans<<endl;
        }else{
            insert(&root,x);
        }
    }
    return 0;
}*/
//下面是正确的（递归建立）
/*
#include<iostream>
#include<cstdio>
#define re register
using namespace std;
const int INF=0x7fffffff;
int cont;
struct node{
    int val,siz,cnt,ls,rs;
}tree[1000010];
int n,opt,xx;
inline void add(int x,int v)
{
    tree[x].siz++;
    if(tree[x].val==v){
        tree[x].cnt++;
        return ;
    }
    if(tree[x].val>v){
        if(tree[x].ls!=0)
          add(tree[x].ls,v);
        else{
            cont++;
            tree[cont].val=v;
            tree[cont].siz=tree[cont].cnt=1;
            tree[x].ls=cont;
        }
    }
    else{
        if(tree[x].rs!=0)
          add(tree[x].rs,v);
        else{
            cont++;
            tree[cont].val=v;
            tree[cont].siz=tree[cont].cnt=1;
            tree[x].rs=cont;
        }
    }
}
int queryfr(int x, int val, int ans) {
    if (tree[x].val>=val)
    {
        if (tree[x].ls==0)
            return ans;
        else
            return queryfr(tree[x].ls,val,ans);
    }
    else
    {
        if (tree[x].rs==0)
            return tree[x].val;
        return queryfr(tree[x].rs,val,tree[x].val);
    }
}
int queryne(int x, int val, int ans) {
    if (tree[x].val<=val)
    {
        if (tree[x].rs==0)
            return ans;
        else
            return queryne(tree[x].rs,val,ans);
    }
    else
    {
        if (tree[x].ls==0)
            return tree[x].val;
        return queryne(tree[x].ls,val,tree[x].val);
    }
}
int queryrk(int x,int rk)
{
    if(x==0) return INF;
    if(tree[tree[x].ls].siz>=rk)
        return queryrk(tree[x].ls,rk);
    if(tree[tree[x].ls].siz+tree[x].cnt>=rk)
        return tree[x].val;
    return queryrk(tree[x].rs,rk-tree[tree[x].ls].siz-tree[x].cnt);
}
int queryval(int x,int val)
{
    if(x==0) return 0;
    if(val==tree[x].val) return tree[tree[x].ls].siz;
    if(val<tree[x].val) return queryval(tree[x].ls,val);
    return queryval(tree[x].rs,val)+tree[tree[x].ls].siz+tree[x].cnt;
}
inline int read()
{
    re int r=0;
    re char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        r=(r<<3)+(r<<1)+(ch^48);
        ch=getchar();
    }
    return r;
}
signed main()
{
    n=read();
    while(n--){
        opt=read();xx=read();
        if(opt==1) printf("%d\n",queryval(1,xx)+1);
        else if(opt==2) printf("%d\n",queryrk(1,xx));
        else if(opt==3) printf("%d\n",queryfr(1,xx,-INF));
        else if(opt==4) printf("%d\n",queryne(1,xx,INF));
        else{
            if(cont==0){
                cont++;
                tree[cont].cnt=tree[cont].siz=1;
                tree[cont].val=xx;
            }
            else add(1,xx);
        }
    }
    return 0;
}
*/
//循环建立
/*
#include<iostream>
#include<cstdio>
#include<vector>
#define pb push_back
const int N = 10010;
const int INF = 0x7fffffff;
inline int read() {
	int r = 0; bool w = 0; char ch = getchar();
	while(ch < '0' || ch > '9') w = ch == '-' ? 1 : w, ch = getchar();
	while(ch >= '0' && ch <= '9') r = (r << 3) + (r << 1) + (ch ^ 48), ch = getchar();
	return w ? ~r + 1 : r;
}
#define ls tree[x].son[0]
#define rs tree[x].son[1]
struct Node {
	int val, siz, cnt, son[2];
}tree[N];
int n, root, tot;
inline void add(int v) {
	if(!tot) {
		root = ++tot;
		tree[tot].cnt = tree[tot].siz = 1;
		tree[tot].son[0] = tree[tot].son[1] = 0;
		tree[tot].val = v;
		return ;
	}
	int x = root, last = 0;
	do {
		++tree[x].siz;
		if(tree[x].val == v) {
			++tree[x].cnt;
			break;
		}
		last = x;
		x = tree[last].son[v > tree[last].val];
		if(!x) {
			tree[last].son[v > tree[last].val] = ++tot;
			tree[tot].son[0] = tree[tot].son[1] = 0;
			tree[tot].val = v;
			tree[tot].cnt = tree[tot].siz = 1;
			break;
		}
	} while(true);//Code by do_while_true qwq
}
int queryfr(int val) {
	int x = root, ans = -INF;
	do {
		if(x == 0) return ans;
		if(tree[x].val >= val) {
			if(ls == 0) return ans;
			x = ls;
		}
		else {
			if(rs == 0) return tree[x].val;
			ans = tree[x].val;
			x = rs;
		}
	} while(true);
}
int queryne(int v) {
	int x = root, ans = INF;
	do {
		if(x == 0) return ans;
		if(tree[x].val <= v) {
			if(rs == 0) return ans;
			x = rs;
		}
		else {
			if(ls == 0) return tree[x].val;
			ans = tree[x].val;
			x = ls;
		}
	} while(true);
}
int queryrk(int rk) {
	int x = root;
	do {
		if(x == 0) return INF;
		if(tree[ls].siz >= rk) x = ls;
		else if(tree[ls].siz + tree[x].cnt >= rk) return tree[x].val;
		else rk -= tree[ls].siz + tree[x].cnt, x = rs;
	} while(true);
}
int queryval(int v) {
	int x = root, ans = 0;
	do {
		if(x == 0) return ans;
		if(tree[x].val == v) return ans + tree[ls].siz;
		else if(tree[x].val > v) x = ls;
		else ans += tree[ls].siz + tree[x].cnt, x = rs;
	} while(true);
}
int main() {
	n = read();
	while(n--) {
		int opt = read(), x = read();
		if(opt == 1) printf("%d\n", queryval(x) + 1);
		if(opt == 2) printf("%d\n", queryrk(x));
		if(opt == 3) printf("%d\n", queryfr(x));
		if(opt == 4) printf("%d\n", queryne(x));
		if(opt == 5) add(x);
	}
	return 0;
}
*/