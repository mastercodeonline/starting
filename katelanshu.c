#include<stdio.h>
//卡特兰数
/*long long f[20][20]={0};
long long dfs(int m,int n);
int main(void){
    int n;
    scanf("%d",&n);
    printf("%lld",dfs(n,0));
    return 0;
}
long long dfs(int m,int n){
    if(f[m][n]){
        return f[m][n];
    }
    if(m==0){
        return 1;
    }
    if(n>0){
        f[m][n]+=dfs(m,n-1);
    }
    f[m][n]+=dfs(m-1,n+1);
    return f[m][n];
}*/
int ttest(void){
    long long f[20][20]={0};
    int n;
    scanf("%d",&n);
    n++;
    f[0][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            f[i][j]=f[i][j-1]+f[i-1][j];
        }
    }
    printf("%lld",f[n][n]-f[n-1][n+1]);
    return 0;
}