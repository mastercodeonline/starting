#include<stdio.h>
int Test(void)
{
    int i,A[1005]={0},B[1005]={0},n,j;//用int维护而非char方便计算
    scanf("%d", &n);
    A[0]=B[0]=1;
    B[1004]=1;
    for (i=2;i<=n;i++){
        for (j=0;j<B[1004];j++)//乘法和近位分为两步，方便计算
            B[j]*=i;
        for (j=0;j<B[1004];j++)
            if (B[j]>9){
                if(j==B[1004]-1){
                    B[1004]++;
                }
                B[j+1] += B[j]/10;
                B[j]%=10;
            }
        for (j=0;j<B[1004];j++){
            A[j]+=B[j];
            if (A[j]>9) {
                if(j==B[1004]-1){
                    B[1004]++;
                }
                A[j+1] += A[j]/10;
                A[j]%=10;
            }
        }
    }
    for (i=B[1004];i>=0&&A[i]==0;i--);//确定位数
    for (j=i;j>=0;j--) printf("%d", A[j]);//其实按照进位规则，只可能最后一位大于9但因为是int
    //可以直接打印
    return 0;
}
       