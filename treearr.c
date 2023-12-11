#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//freopen("input.in","r",stdin);
int arr[1000];
int n,m;
int test(void){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    int k=0;
    while(n>=1){
        if(k+m<=n){
            printf("%d ",arr[k+m]);
            k+=m;
            n--;
            memmove(arr+k,arr+k+1,(n-k+1)*sizeof(int));
            k--;
        }else{
            k+=m;
            while(k>n){//这里可以判断位k=(k+m)%n;;;!!!!!
                k-=n;
            }
            printf("%d ",arr[k]);
            n--;
            memmove(arr+k,arr+k+1,(n-k+1)*sizeof(int));
            k--;
        }
    }
    return 0;
}
/*
#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=3e4+10;
int n,m,maxx;
int bit[maxn];

inline int lowbit(int x)
{
	return x&-x;
}
inline void add(int pos,int x)
{
	for(int i=pos;i<=maxx;i+=lowbit(i))bit[i]+=x;
}
inline int find_kth(int k)
{
	int ans=0,now=0;
	for(int i=15;i>=0;i--)
	{
		ans+=(1<<i);
		if(ans>maxx||bit[ans]+now>=k)ans-=(1<<i);
		else now+=bit[ans];
	}
	return ans+1;
}

int main()
{
	scanf("%d %d",&n,&m);
	maxx=n;		//这里因为n后面会改变，所以先记录一下n的值。 
	for(int i=1;i<=n;i++)bit[i]=lowbit(i);//这里完全等价于add(i,1),因为一开始都是1，所以bit[i]=i-(i-lowbit(i)+1)+1=lowbit(i) 
	int now=1;//从1开始 
	while(n)
	{
		now=(now-1+m-1)%n+1;//这里是小细节，本来的式子应该是(now+m-1)%n的，但是考虑如果只剩下2个元素，而我们当前要找的就是第二个元素呢？直接模就是0了，所以用一个+1 -1 的小操作更改取模运算的值域，这样就可以取到n的值了，而对别的无影响 
		int ans=find_kth(now);//找kth 
		add(ans,-1);//把这个人删除 
		printf("%d ",ans);
		n--;
	}
	return 0;
}
*/