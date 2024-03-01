#include<iostream>
#include<algorithm>
#include<stack>
#include<set>
#include<unordered_set>
#include<queue>
#include<deque>
using namespace std;
struct edge{
    int v;
    int node;
    int next;
};///图边建立
struct ele{
    int x;
    int y;
    int v;
    bool operator<(ele x){
        if(this->v<x.v){
            return true;
        }else{
            return false;
        }
    }
};//预处理需要，决定建图的顺序
edge e[400001];//图数组
ele arr[200001];//存边信息
int head[200001];//存头节点
int cnt;//进行编号
void add(int x,int y,int value){
    e[++cnt].next=head[x];
    e[cnt].node=y;
    e[cnt].v=value;
    head[x]=cnt;
}//加边操作
//重新建图，只要清空head数组并把cnt归零即可