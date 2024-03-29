#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//质数的选择ull mod1=19260817;
//ull mod2=19660813;
//ull mod=212370440130137957ll;//是质数！！
//freopen("input.in","r",stdin);
unsigned int SDBMHash(char *str)
{
    unsigned int hash = 0;
 
    while (*str)
    {
        // equivalent to: hash = 65599*hash + (*str++);
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
    }
 
    return (hash & 0x7FFFFFFF);
}
//可以设计好几个求模的数，建立多个哈希函数
int bas=131;
unsigned long long harsh(char*str){
    int n=strlen(str);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=(ans*bas+str[i])%212370440130137957ll;
    }
    return ans;
}


//自然溢出
unsigned long long harsh2(char*str){
    int n=strlen(str);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans*bas+str[i];
    }
    return ans&0x7fffffff;
}



int arr[100005][2];
int test(void){
    int n,m;
    freopen("input.in","r",stdin);
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<m;i++){
        char buff[50]="\0";
        char* p=buff;
        scanf("%c",&buff[0]);
        if(buff[0]=='1'){
            char buff2[50]={'\0'};
            scanf("%s",buff2);
            strcat(buff,buff2);
            scanf("%s",buff2);
            strcat(buff,buff2);
            int re=0;
            scanf("%d",&re);
            getchar();
            int index=SDBMHash(buff+1)%100000;
            arr[index][0]++;
            arr[index][1]=re;
        }else{
            char buff2[50]={'\0'};
            scanf("%s",buff2);
            strcat(buff,buff2);
            scanf("%s",buff2);
            strcat(buff,buff2);
            getchar();
            int index=SDBMHash(buff+1)%100000;
            printf("%d\n",arr[index][1]);
        }
    }
    return 0;
}
/*
据我的理解，Hash就是一个像函数一样的东西，你放进去一个值，它给你输出来一个值。输出的值就是Hash值。一般Hash值会比原来的值更好储存(更小)或比较。

那字符串Hash就非常好理解了。就是把字符串转换成一个整数的函数。而且要尽量做到使字符串对应唯一的Hash值。

字符串Hash的种类还是有很多种的，不过在信息学竞赛中只会用到一种名为“BKDR Hash”的字符串Hash算法。

它的主要思路是选取恰当的进制，可以把字符串中的字符看成一个大数字中的每一位数字，不过比较字符串和比较大数字的复杂度并没有什么区别(高精数的比较也是
�
(
�
)
O(n)的)，但只要把它对一个数取模，然后认为取模后的结果相等原数就相等，那么就可以在一定的错误率的基础上
�
(
1
)
O(1)进行判断了。

那么我们选择什么进制比较好？

首先不要把任意字符对应到数字0，比如假如把a对应到数字0，那么将不能只从Hash结果上区分ab和b（虽然可以额外判断字符串长度，但不把任意字符对应到数字0更加省事且没有任何副作用），一般而言，把a-z对应到数字1-26比较合适。

关于进制的选择实际上非常自由，大于所有字符对应的数字的最大值，不要含有模数的质因子(那还模什么)，比如一个字符集是a到z的题目，选择27、233、19260817 都是可以的。

模数的选择（尽量还是要选择质数）：

绝大多数情况下，不要选择一个
1
0
9
10 
9
 级别的数，因为这样随机数据都会有Hash冲突，根据生日悖论，随便找上
1
0
9
10 
9
 
​
 个串就有大概率出现至少一对Hash 值相等的串（参见BZOJ 3098 Hash Killer II）。

最稳妥的办法是选择两个
1
0
9
10 
9
 级别的质数，只有模这两个数都相等才判断相等，但常数略大，代码相对难写，目前暂时没有办法卡掉这种写法（除了卡时间让它超时）（参见BZOJ 3099 Hash Killer III）。

如果能背过或在考场上找出一个
1
0
1
8
10 
1
 8级别的质数(Miller-Rabin)，也相对靠谱，主要用于前一种担心会超时，后一种担心被卡。

偷懒的写法就是直接使用unsigned long long，不手动进行取模，它溢出时会自动对
2
6
4
2 
//处理哈希冲突的方法——————后寻址法
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define hmod 4698571    //对于Hash数组的mod值
inline ll read();

ll Hash[hmod+123456];   //Hash需开大一点

inline bool find(ll x)
{
	ll wh=abs(x%hmod);   //对于负数只需处理一个定值即可，表示位置
	while (Hash[wh]!=1808504320951916825)//如果当前位置有数
	{
		if (Hash[wh]==x) //查看是否为此数
			return true; //返回true
		else
			++wh;      //否则查找下一个位置
	}
	Hash[wh]=x;       //没找到则放入Hash中
	return false;      //返回false
}

ll t,n;

int main()
{
	t=read();
	while (t--)
	{
		memset(Hash,25,sizeof(Hash));//每次将Hash赋初始值，此时Hash中的值正是1808504320951916825（随便乱赋的值）
		n=read();
		for (register int i=1;i<=n;++i)
		{
			ll k=read(); //每次读入k
			if (!find(k))//如果k没进入数组
				cout<<k<<" ";//输出（"放入"已经在函数中执行了）
		}
		cout<<endl;     //回行
	}
	return 0;
}

inline ll read()		//快读（不解释了）
{
	ll x=0,f=0;
	char c=getchar();
	while (!isdigit(c))
		f|=c=='-',c=getchar();
	while (isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}




6
 4进行取模，如果出题人比较良心，这种做法也不会被卡，但这个是完全可以卡的，卡的方法参见BZOJ 3097 Hash Killer I。
*/
//康托展开（全排列适用，可逆展开）
//对哈希的空间压缩
//string a=Ai*(n-1)!+.....+;
//Ai为小于该字符且没有固定的字符数
