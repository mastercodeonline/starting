#include<iostream>
#include<cmath>
using namespace std;
//枚举因子或者枚举公约数倍数
//看情况而定
//这题中枚举倍数超时了
//gcd结论
//a b 互质<-->gcd(a,b)==1;
//gcd(a,b)=c<-->gcd(a/c,b/c)==1;
//基于以上结论
//gcd(c/a,c/b)=1<-->c 为a b 的最小公倍数
int judge(int x,int y){
    if(y==1){
        return 1;
    }
    while(x%y>1){
        x=x%y;
        int t=x;
        x=y;
        y=t;
    }
    return x%y;
}
int get(int x,int y){
    if(y==1){
        return 1;
    }
    while(x%y>0){
        x=x%y;
        int t=x;
        x=y;
        y=t;
    }
    return y;
}
int test(void){
    int n;
    freopen("input.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        int a0,a1,b0,b1;
        int re=0;
        cin>>a0>>a1>>b0>>b1;
        int k=a0/a1;
        int kk=b1/b0;
        for(int j=1;j<=sqrt(b1);j++){
            if(b1%j!=0){
                continue;
            }
            if(j%a1==0){
                if(judge(b1/j,kk)&&judge(j/a1,k)){
                    re++;
                }
            }
            int tmp=j;
            j=b1/j;
            if(j==tmp){
                continue;
            }
            if(j%a1==0){
                if(judge(b1/j,kk)&&judge(j/a1,k)){
                    re++;
                }
            } 
            j=tmp;           
        }
        cout<<re<<endl;
    }
    return 0;
}