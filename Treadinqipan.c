#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int qipan[20][20]={0};
int rea[4][20]={0};
int y[20]={0},p[40]={0},q[40]={0};//直线的表示方法，以此排除线性关系
int n;
int re=0;
void dfs(int i,int x1){
    if(re<3){
        rea[re][x1-1]=i;
    }
    if(x1==n){
        re++;
        if(re<3){
            memmove(rea+re,rea+re-1,20*sizeof(int));//越界修改，数据报错，但程序不会停，烦人
        }
        return;
    }
    q[x1+i]=1;
    y[i]=1;
    p[x1-i+n]=1;
    //p[i-x1+n]=1;
    for(int j=1;j<=n;j++){
        if(!y[j]&&!p[x1+1-j+n]&&!q[x1+1+j]){
            dfs(j,x1+1);
        }
    }
    y[i]=0;
    p[x1-i+n]=0;
    q[x1+i]=0;
    //p[i-x1+n]=0;
    return;
}
int Test(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        dfs(i,1);
    }
    for(int j=0;j<3;j++){
        for(int i=0;i<n;i++){
            printf("%d ",rea[j][i]);
        }
        printf("\n");
    }
    printf("%d",re);
    return 0;
}
