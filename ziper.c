#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ziper(void);
char string[21000]="\0";

void ziper(void){
    int i=0;
    int j,k;
    int flag=0;
    int fflag=0;
    while(string[i]){
        if(string[i]=='['){
            if(flag==0){
                j=i;
            }
            flag++;
            i++;
            continue;
        }else if(string[i]==']'){
            flag--;
            if(flag==0){
                k=i;
                int ffflag=0;
                int time=string[j+1]-'0';
                if(string[j+2]>'0'-1&&string[j+2]<'9'+1){
                    time*=10;
                    time+=string[j+2]-'0';
                    ffflag=1;
                }
                int n=k-j-2-ffflag;//字符数
                int move=time*n-k+j-1;
                i+=move;
                char*buff=(char*)malloc(n*sizeof(char));
                for(int i=0;i<n;i++){
                    buff[i]=string[j+2+i+ffflag];
                }
                memmove(string+k+1+move,string+k+1,strlen(string+k+1));
                if(move<0){
                    int ns=strlen(string);
                    for(int p=0;p<-move;p++){
                        string[ns-1-p]='\0';
                    }
                }
                for(int a=0;a<time;a++){
                    for(int b=0;b<n;b++){
                        string[j+b+a*n]=buff[b];
                    }
                }
                fflag++;
                free(buff);
                buff=NULL;
            }
            i++;
            continue;
        }else{
            i++;
            continue;
        }
    }
    if(fflag){
        ziper();
    }
}
