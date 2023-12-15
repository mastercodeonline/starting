#include<iostream>
#include<cmath>
#include<cstring>
//二叉树绘图
//
using namespace std;
char  re[1028][3000];
int dele[11][1028];
void dfs(int deep,int rank,int n,int x,int y){
    if(n==deep){
        return;
    }
    if(dele[deep+1][rank*2]==0){
        int num=3*pow(2,n-deep-2)-1;
        if(num==0){
            num=1;
        }
        int i=1;
        for(i=1;i<=num;i++){
            re[y+i][x+i]='\\';
        }
        re[y+i][x+i]='o';
        dfs(deep+1,rank*2,n,x+i,y+i);
    }
    if(dele[deep+1][rank*2-1]==0){
        int num=3*pow(2,n-deep-2)-1;
        if(num==0){
            num=1;
        }
        int i=1;
        for(i=1;i<=num;i++){
            re[y+i][x-i]='/';
        }
        re[y+i][x-i]='o';
        dfs(deep+1,rank*2-1,n,x-i,y+i);        
    }
}
int test2(void){
    int n;
    freopen("input.in","r",stdin);
    cin>>n;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        dele[a][b]=1;
    }
    int start=3;
    int height=3;
    for(int i=2;i<n;i++){
        start=start*2+3;
        height*=2;
    }
    int y=1;
    int x=2+start/2;
    memset(re,32,sizeof(re));
    
    re[y][x]='o';
    dfs(1,1,n,x,y);
    for(int i=1;i<=height;i++){
        re[i][start+3]='\0';
        cout<<re[i]+1<<endl;
    }
    return 0;
}
//南蛮图腾
/*
#include <stdio.h>
#include <string.h>
int P2[]={1,2,4,8,16,32,64,128,256,512,1024,2048};  
char Map[2049][2049];   
int N;
void Pt1(int pyh,int pyl)  
{
    Map[pyh][pyl]='/';
    Map[pyh][pyl+1]='\\';
    Map[pyh+1][pyl-1]='/';
    Map[pyh+1][pyl+2]='\\';
    Map[pyh+1][pyl]='_';
    Map[pyh+1][pyl+1]='_';
}
void Divide(int py1,int py2,int n) 
{
    if(n==1){Pt1(py1,py2);return;} 
    Divide(py1,py2,n-1);  
    Divide(py1+P2[n-1],py2-P2[n-1],n-1);
    Divide(py1+P2[n-1],py2+P2[n-1],n-1);
}
int test()
{
    scanf("%d",&N);
    memset(Map,' ',sizeof(Map));  
    Divide(0,P2[N],N);
    int wia,wib;
    for(wia=0;wia<P2[N+1];++wia)
    {
        for(wib=1;wib<=P2[N+1];++wib)
            putchar(Map[wia][wib]);
        putchar('\n');
    }   
    return 0;
}
*/