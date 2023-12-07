#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
double dp[20][34000];
double arr[20][2]={0};
double min1(double a,double b){
    return a>b?b:a;
}//写位运算时尽量加括号，貌似运算等级太低，可能得到错误结果
int test(void){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&arr[i][0],&arr[i][1]);
    }
    memset(dp,127,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[i][1<<(i-1)]=sqrt(pow(arr[i][0]-arr[0][0],2)+pow(arr[i][1]-arr[0][1],2));
    }
    for(int i=1;i<(1<<(n));i++){
        for(int j=1;j<=n;j++){
            if((i&(1<<(j-1)))==0){
                continue;
            }
            for(int k=1;k<=n;k++){
                if((i&(1<<(k-1)))==0){
                    continue;
                }
                if(j==k){
                    continue;
                }
                dp[j][i]=min1(dp[j][i],dp[k][i-(1<<(j-1))]+sqrt(pow(arr[j][0]-arr[k][0],2)+pow(arr[j][1]-arr[k][1],2)));
            }
        }
    }
    double ans=dp[1][(1<<n)-1];
    for(int i=2;i<=n;i++){
        ans=min1(ans,dp[i][(1<<n)-1]);
    }
    printf("%.2lf",ans);
    return 0;
}