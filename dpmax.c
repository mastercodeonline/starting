#include<stdlib.h>
#include<stdio.h>
int arr[5][25]={0};
int max1(int a,int b){
    return a>b?a:b;
}
int test(void){
    int s[4];
    scanf("%d%d%d%d",&s[0],&s[1],&s[2],&s[3]);
    for(int i=0;i<4;i++){
        for(int j=1;j<=s[i];j++){
            scanf("%d",&arr[i][j]);
            arr[i][s[i]+1]+=arr[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<4;i++){
        int dp[24][2501]={0};
        for(int j=1;j<=s[i];j++){
            for(int k=arr[i][s[i]+1]/2;k>=1;k--){//这里没有顺序需要从一开始
                if(k<arr[i][j]){
                    dp[j][k]=dp[j-1][k];
                }else{
                    dp[j][k]=max1(dp[j-1][k],dp[j-1][k-arr[i][j]]+arr[i][j]);
                }
            }
        }
        sum+=max1(arr[i][s[i]+1]-dp[s[i]][arr[i][s[i]+1]/2],dp[s[i]][arr[i][s[i]+1]/2]);
    }
    printf("%d",sum);
    return 0;
}