#include<stdio.h>
#include<stdlib.h>
int arr[1005][3]={0};
int sum[1001]={0};
int cmp(const void*p1,const void*p2){
    return *((int*)p1+2)-*((int*)p2+2);
}
int chufa(int n){
    int result=0;//记录最终结果
    int buff=0;//记录目前的余数
    int pow=1;
    int num;//记录目前的除数
    for(int i=1;i<sum[999];i++){
        pow*=10;
    }//记录增加的位数
    for(int i=0;i<sum[999];i++){
        buff=buff*10+sum[sum[999]-1-i];
        num=buff/n;
        buff=buff-n*num;
        result+=num*pow;
        pow/=10;
    }
    return result;
}
void chengfa(int n){
    for(int i=0;i<sum[999];i++){
        sum[i]*=n;
    }//乘法
    for(int i=0;i<sum[999];i++){
        if(sum[i]>9){
            if(i==sum[999]-1){
                sum[999]++;
            }
            sum[i+1]+=sum[i]/10;
            sum[i]%=10;
        }
    }//进位
}
int Test(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%d%d",&arr[i][0],&arr[i][1]);
        arr[i][2]=arr[i][1]*arr[i][0];
    }
    qsort(arr+1,n,sizeof(arr[0]),cmp);
    sum[0]=arr[0][0];
    sum[999]=1;
    for(int i=0;i<sum[999];i++){
        if(sum[i]>9){
            if(i==sum[999]-1){
                sum[999]++;
            }
            sum[i+1]+=sum[i]/10;
            sum[i]%=10;
        }
    }
    int max=0;
    for(int i=1;i<=n;i++){
        int num=chufa(arr[i][1]);
        chengfa(arr[i][0]);
        if(num>max){
            max=num;
        }
    }
    printf("%d",max);
    return 0;
}
/*
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int a,b;
	char cnta[10000],all[10000];//cnta 为前面所有a的乘积的逆序 all为乘积正序 
	char ca[100];//a转化为字符数组 
	char ans[10000];//所获得金币数 
	int lans;
}da[1001];
bool cmp(node a,node b){
	return a.a*a.b<b.a*b.b;
}
bool cmp2(node a,node b){//高精度比较 
	if(a.lans!=b.lans)
		return a.lans>b.lans;
	else{
		int i;
		for(i=0;i<a.lans;i++)
			if(a.ans[i]==b.ans[i]) {
				continue;
			}
			else return a.ans[i]>b.ans[i];
	}
	return 1==1;
}
void doit(int a,char b[]){//将数值转化成字符数组
	int lb=0;
	while(a>0){
		b[lb++]=a%10+'0';
		a/=10;
	}
	b[lb]='\0';
}
void add(char c[],char d[],int i){//错位相加 
	int lc=strlen(c),j;
	int jw = 0,tmp;
	for(j=0;j<lc;j++,i++){
		tmp=(d[i]>0?d[i]-'0':0)+c[j]-'0'+jw;
		d[i]=tmp%10+'0';
		jw=tmp/10;
	}
	if(jw){
		d[i++]=jw+'0';
	}
	d[i]='\0';
}
void gc(char a[],char b[],char d[]){//高乘 
	int la=strlen(a);
	int lb=strlen(b);
	int i,j;
	char c[10000];//记录乘数的每一位乘以被乘数的积 
	for(i=0;i<la;i++){
		int tmp;
		int jw = 0;
		int lc = 0;
		for(j=0;j<lb;j++){
			tmp = (a[i]-'0') * (b[j]-'0') + jw;
			c[lc++] = tmp % 10 + '0';
			jw = tmp / 10;
		}
		if(jw) c[lc++]=jw+'0';
		c[lc]='\0';
		add(c,d,i);
	}
}
void mult(char a[],int b, char c[]){
	int i = 0 , tag = 0 , la = strlen(a) , lc = 0;
	int d = 0;
	while(i<=la){
		if(b>d){
			d=d*10+a[i++]-'0';
			if(tag) c[lc++]='0';
		}else{
			c[lc++]=d/b+'0';
			d=d%b;
			d=d*10+a[i++]-'0';
			tag = 1;
		}
	}
	if(tag==0)c[lc++]='0';
	c[lc]='\0';
}
int main(){
	int n,i,j;
	memset(da,0,sizeof(da));
	scanf("%d",&n);
	scanf("%d%d",&da[0].a,&da[0].b);
	for(i=1;i<=n;i++){
		scanf("%d%d",&da[i].a,&da[i].b);
	}
	sort(da+1,da+n+1,cmp);
	doit(da[0].a,da[0].ca); 
	da[0].cnta[0]='1';
	da[0].cnta[1]='\0';
	for(i=1;i<=n;i++){//得到前面大臣左手金币数的乘积的逆序 
		doit(da[i].a,da[i].ca);
		gc(da[i-1].cnta,da[i-1].ca,da[i].cnta);
	}
	for(i=1;i<=n;i++){//将乘积逆转 
		int k=0;
		for(j=strlen(da[i].cnta)-1;j>=0;j--)
			da[i].all[k++]=da[i].cnta[j];
		da[i].all[k]='\0';
	}
	for(i=1;i<=n;i++){//得到每一位大臣能获得的金币数 
		mult(da[i].all,da[i].b,da[i].ans);
		da[i].lans = strlen(da[i].ans);
	}
	int ans = 1;
	for(i=2;i<=n;i++){
		if(!cmp2(da[ans],da[i]))
			ans=i;
	}
	printf("%s\n",da[ans].ans);
	return 0;
}
*/