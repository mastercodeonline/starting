#include<stdio.h>
int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int test(void){
    long long f[40][40]={0};
    int s[40][40]={0};
    int x,y,m,n;
    scanf("%d%d%d%d",&x,&y,&m,&n);
    x+=2;y+=2;m+=2;n+=2;
    f[2][1]=1;
    for(int i=0;i<=8;i++){
        s[m+fx[i]][n+fy[i]]=1;//设置零点
    }
    for(int i=2;i<=x;i++){//模拟杨辉三角递加过程
        for(int j=2;j<=y;j++){
            if(s[i][j]){
                continue;
            }
            f[i][j]=f[i-1][j]+f[i][j-1];
        }
    }
    printf("%lld",f[x][y]);
    return 0;
}