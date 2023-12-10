#include<stdio.h>

int v[105][105]={0};
int arr[105][105]={0};
int move[8][2]={{0,1},{1,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
int n,m;
int re=0;
int judge(int x,int y){
    return x>=1&&y>=1&&y<=m&&x<=n&&v[x][y]==0;
}
void dfs(int x,int y){
    v[x][y]=1;
    for(int i=0;i<8;i++){
        if(arr[x+move[i][0]][y+move[i][1]]==1){
            if(judge(x+move[i][0],y+move[i][1])){
                dfs(x+move[i][0],y+move[i][1]);
            }
        }
    }
}
int test(void){
    //freopen("C://Users//86157//Downloads//P1596_1.in","r",stdin);
    scanf("%d%d",&n,&m);
    char buff[105]="\0";
    for(int i=1;i<=n;i++){
        scanf("%s",buff+1);
        for(int j=1;j<=m;j++){
            if(buff[j]=='W'){
                arr[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(judge(i,j)&&arr[i][j]==1){
                dfs(i,j);
                re++;
            }
        }
    }
    printf("%d",re);
    return 0;
}
/*
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
*/