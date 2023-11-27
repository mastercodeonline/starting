#include<stdio.h>
void dfs(int x,int y,int a,int b,int len);
int main(void){
    int k,x,y;
    scanf("%d%d%d",&k,&x,&y);
    int len=1;
    for(int i=0;i<k;i++){
        len*=2;
    }
    dfs(x,y,len/2,len/2,len);
    return 0;
}
//关键在于中心判断，但要求有一个阻隔点，不然无法递推
//所以将填上的三个点设为阻隔点，以此进行递归；
void dfs(int x,int y,int a,int b,int len){
    if(len==1){
        return;
    }
    if(x<=a&&y<=b){
        printf("%d %d 1\n",a+1,b+1);
        dfs(x,y,a-len/4,b-len/4,len/2);
        dfs(a,b+1,a-len/4,b+len/4,len/2);
        dfs(a+1,b+1,a+len/4,b+len/4,len/2);
        dfs(a+1,b,a+len/4,b-len/4,len/2);
    }else if(x<=a&&y>b){
        printf("%d %d 2\n",a+1,b);
        dfs(a,b,a-len/4,b-len/4,len/2);
        dfs(x,y,a-len/4,b+len/4,len/2);
        dfs(a+1,b+1,a+len/4,b+len/4,len/2);
        dfs(a+1,b,a+len/4,b-len/4,len/2);
    }else if(x>a&&y>b){
        printf("%d %d 4\n",a,b);
        dfs(a,b,a-len/4,b-len/4,len/2);
        dfs(a,b+1,a-len/4,b+len/4,len/2);
        dfs(x,y,a+len/4,b+len/4,len/2);
        dfs(a+1,b,a+len/4,b-len/4,len/2);
    }else{
        printf("%d %d 3\n",a,b+1);
        dfs(a,b,a-len/4,b-len/4,len/2);
        dfs(a,b+1,a-len/4,b+len/4,len/2);
        dfs(a+1,b+1,a+len/4,b+len/4,len/2);
        dfs(x,y,a+len/4,b-len/4,len/2);
    }
}
