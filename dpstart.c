#include<stdio.h>
#include<stdlib.h>
/*int f[105][10005]={0};
//dp实现
//要求从小开始算
//找到转移方程
int main(void){
   int m,n;
   int arr[105];
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
   }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j==arr[i]){
                f[i][j]=f[i-1][j]+1;
            }else if(j>arr[i]){
                f[i][j]=f[i-1][j]+f[i-1][j-arr[i]];
            }else{
                f[i][j]=f[i-1][j];
            }
        }
    }
    printf("%lld",f[n][m]);
    return 0;
}
*/
/*
//将维度将为一维
//原理：i每次转移均为i-1
//但需要注意到，将维后数组滚动变化
//而原先数组0行均为0，若m从小变化，会赋值低位，而非初始数
//所以选择从大变化
int v[101],f[10005]={0};
int main(void){
    int m,n;
    f[0]=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
                f[j]=f[j]+f[j-v[i]];
            }
        }
    printf("%d",f[m]);
    return 0;
}
*/
//dfs暴力递归从大到小
//好像可以不求没必要的值，要用return，返回不可分割的值
//但递归极易爆栈，浪费时间
//两种递归
//1：以每个菜被选为前提，加上循环
/*
int f[101][10001]={0},v[101];
int dfs(int n,int m){
    if(f[n][m]){
        return f[n][m];
    }
    if(m==v[n]){
        return 1;
    }
    if(m<v[n]){
        return 0;
    }

    if(m>v[n]){
        f[n][m]+=dfs(n-1,m-v[n]);
    }
}
*/
//2:通过判断菜是非被选中，进行步骤递归
//类似与电路开关，但区别为灯的权重不同
//值得注意的是这里没有限定个数，若限定个数，则可以多加一个标志位
int n=0;
int a,b,v[101];
void dfs(int step,int m){
    if(m==0){
        n++;
        return;
    }
    if(step==a+1){
        return ;
    }
    if(m>=v[step]){
        dfs(step+1,m);
        dfs(step+1,m-v[step]);
    }
    else{
        return;
    }
}
int test(void){
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a;i++){
        scanf("%d",&v[i]);
    }
    dfs(1,b);
    printf("%d",n);
    return 0;
}