#include<stdio.h>
#include<string.h>
char role[6][2][25];//bfs算法一般可以求最优解，dfs算法一般求种类数
int re=1;
int index1[6][21]={{0}};
char queue[100][21];
int head=0;
char repeat[200][21];
int num=0;
char string1[25];
char string2[25];
int kmp(char*s1,int n){//kmp算法（改进版）
    int i=0,j=0;
    for(;i<strlen(s1);){
        if(j==-1||s1[i]==role[n][0][j]){
            i++;
            j++;
        }else{
            j=index1[n][j];
        }
        if(strlen(role[n][0])==j){
            return i-strlen(role[n][0]);
        }
    }
    return -1;
}
void getindex(int n){
    int j=0,k=-1;
    index1[n][0]=-1;
    while(j<strlen(role[n][0])-1){
        if(k==-1||role[n][0][j]==role[n][0][k]){
            j++;
            k++;
            if(role[n][0][j]!=role[n][0][k]){
                index1[n][j]=k;
            }else{
                index1[n][j]=index1[n][k];
            }
        }else{
            k=index1[n][k];
        }
    }
}
void bfs(int n){
    int regflag=0;
    for(int i=0;i<n;i++){
        int index=0;
        int y=0;
        while(index!=-1&&y<strlen(string1)){
            index=kmp(string1+y,i);
            y=index+strlen(role[i][0]);
            if(index!=-1){
                char buff[21]="\0";
                memmove(buff,string1,index);
                strcat(buff,role[i][1]);
                strcat(buff,string1+index+strlen(role[i][0]));
                if(strcmp(string2,buff)==0){
                    return;
                }
                int flag=0;
                for(int i=0;i<num;i++){
                    if(strcmp(buff,repeat[i])==0){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    regflag=1;
                    num++;
                    head++;
                    memmove(queue+1,queue,head*21);
                    strcat(queue[0],buff);
                    strcat(repeat[num-1],buff);
                }
            }
        }
    }
    if(regflag==1){
        re++;
    }
    int n1=num;
    int diff=num;
    while(head!=0){
        char string[21]="\0";
        strcat(string,queue[head-1]);
        memset(queue[head-1],0,21);
        head--;
        diff--;
        regflag=0;
        for(int i=0;i<n;i++){
        int index=0;
        int y=0;
        while(index!=-1&&y<strlen(string)){
            index=kmp(string+y,i);
            y=index+strlen(role[i][0]);
            if(index!=-1){
                char buff[21]="\0";
                memmove(buff,string,index);
                strcat(buff,role[i][1]);
                strcat(buff,string+index+strlen(role[i][0]));
                if(strcmp(string2,buff)==0){
                    return;
                }
                int flag=0;
                for(int i=0;i<num;i++){
                    if(strcmp(buff,repeat[i])==0){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    num++;
                    head++;
                    memmove(queue+1,queue,head*21);
                    strcat(queue[0],buff);
                    strcat(repeat[num-1],buff);
                }
            }
        }
        }
        if(diff==0){
            n1=num;
            diff=num-n1;
            n1=num;
            re++;
            if(re==11){
                return;
            }
        }
    }
    re=-1;
    return;
}
int test(void){
    scanf("%s",string1);
    scanf("%s",string2);
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",role[i][0]);
        scanf("%s",role[i][1]);
    }
    for(int i=0;i<n;i++){
        getindex(i);
    }
    bfs(n);
    printf("%d",re);
    return 0;
}