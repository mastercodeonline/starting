#include<stdio.h>
#include<string.h>
int v[205]={0};
int n,a,b;
int move[205]={0};
int re=1;
int ans=-1;
int queue[4000]={0};
int head=0;
int n1;
int num=0;
int diff;
int judge(int x){
    return x>0&&x<=n&&v[x]==0;
}
int in(int x){
    if(judge(x-move[x])){
        if(x-move[x]==b){
            return re;
        }
        num++;
        memmove(queue+1,queue,head*sizeof(int));
        head++;
        v[x-move[x]]=1;
        queue[0]=x-move[x];
    }
    if(judge(x+move[x])){
        if(x+move[x]==b){
            return re;
        }
        num++;
        memmove(queue+1,queue,head*sizeof(int));
        head++;
        v[x+move[x]]=1;
        queue[0]=x+move[x];
    }
    return 0;
}
void dfs(int x){
    v[x]=1;
    ans=in(x);
    if(ans){
        return;
    }
    n1=num;
    diff=num;
    re++;
    while(head){
        x=queue[head-1];
        head--;
        diff--;
        ans=in(x);
        if(ans){
            return;
        }
        if(diff==0){
            re++;
            diff=num-n1;
            n1=num;
        }
    }
}
int test(void){
    scanf("%d%d%d",&n,&a,&b);
    if(a==b){
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&move[i]);
    }
    dfs(a);
    if(ans){
        printf("%d",ans);
    }else{
        printf("-1");
    }
    return 0;
}
