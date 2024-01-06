#include<iostream>
#include<algorithm>
#include<cmath>
#include<unordered_set>
#include<cstring>
using namespace std;
//素数筛选
//1 埃氏筛
/*
bool v[100000005];
int re[5770000];
int main(void){
    int n;
    freopen("input.in","r",stdin);
    cin>>n;
    int k=0;
    for(int i=2;i<=n;i++){
        if(v[i]){
            continue;
        }
        re[k]=i;
        k++;
        if(i<sqrt(n)){
            int m=i*i;
            while(m<n){
                v[m]=1;
                m+=i;
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a;
        cin>>a;
        cout<<re[a-1]<<endl;
    }
    return 0;
}*/
//欧拉筛（线性筛）
bool v[20000];
int re[577];
int test(void){
    int n;
    //freopen("input.in","r",stdin);
    cin>>n;
    int k=0;
    for(int i=2;i<=n;i++){
        if(!v[i]){
            re[k]=i;
            k++;
        }
        for(int j=0;j<k;j++){
            if((long long) i*re[j]>n){
                break;
            }
            v[i*re[j]]=1;
            if(i%re[j]==0){
                break;
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a;
        cin>>a;
        cout<<re[a-1]<<endl;
    }
    return 0;
}
//两种方法的选择
//其实两者的效率欧拉晒略胜一筹，但前者只需在开方次数就可以确定所有那些素数，那些不是素数
//并且若选择消除前面所有素数的影响（通过筛选是除去开方以下的素数），最后可以完成质因数分解
//通常情况下，两者可以结合使用，同欧拉筛确定小范围素数，用埃氏筛思想进行操作
//洛谷P3601
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 5;
const int mod = 666623333;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    if (ch == '-')
        f = -1, ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        {
            x = x * 10 + ch - 48;
            ch = getchar();
        }
    return x * f;
}
int a[maxn], prime[maxn], phi[maxn], vis[maxn], cnt;
int ans;
void oula_prime() //素数筛法这里就用线性筛即可，相信过来看题解的 dalao 们会的比我多多了qaq
{
    for (int i = 2; i < maxn; i++)
    {
        if (a[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] * i < maxn; j++)
        {
            a[prime[j] * i] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
signed main()
{
    int l = read(), r = read();
    for (int i = 0; i < maxn; i++)
        a[i] = true;
    oula_prime();
    for (int i = l; i <= r; i++)
    {
        vis[i - l] = i;
        phi[i - l] = i;
    }
    for (int i = 0; i < cnt && prime[i] * prime[i] <= r; i++)
    {
        int pr = prime[i], begn = l;
        if (l % pr != 0)
            begn = l / pr * pr + pr;
        for (int j = begn; j <= r; j += pr)
        {
            phi[j - l] = phi[j - l] / pr * (pr - 1);
            while (vis[j - l] % pr == 0)
                vis[j - l] /= pr;
        }
    }
    for (int i = l; i <= r; i++)
    {
        if (vis[i - l] > 1)
            phi[i - l] = phi[i - l] / vis[i - l] * (vis[i - l] - 1);
        ans = (ans + (i - phi[i - l]) % mod) % mod; /*这里需要特别注意，我们的统计可能是不完全的，所以要处理剩下的大因数，就是那些最多有一个超过根号r的因数

        并且，更加需要注意的事情，
        错误写法:ans += i - phi[i - l] % mod;

        正确写法:ans = (ans + (i - phi[i - l]) % mod) % mod;

        因为在 % mod，的时候你以为你以为的就是你以为的啊，ans 的部分并不会取模，俄日是直接作为一个加数直接加上了

        模 法 惨 案
        */
    }
    printf("%lld\n", ans);
    return 0;
}
