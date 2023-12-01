#include<stdio.h>
#include<stdlib.h>
int cmp(const void*p1,const void*p2){
    return *((long long*)p1)-*((long long*)p2);
}
int  arr[10005]={0};
int b[20005]={0};
int Test(void){
    int n;
    scanf("%d",&n);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        b[x]++;
    }
    int j=0;
    for(int i=1;i<20001;i++){
        while(b[i]){
            b[i]--;
            arr[j]=i;
            j++;
        }
    }
    int sum1=arr[0];
    int sum2=0;
    for(int i=1;i<n;i++){
        sum1+=arr[i];
        sum2+=sum1;
        arr[i]=sum1;
        for(int j=i;j<n-1;j++){
            if(arr[j]>sum1){
                break;
            }
            if(arr[j]>arr[j+1]){
                long long t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
        sum1=arr[i];
    }
    printf("%d",sum2);
    return 0;
}
/*只需要看后两个数大小即可判断下一次合并情况


int sum()//合并部分！！我自己看的都头晕争取让大家看懂！！
{
    int Af,Ae,Bf=1,Be,sum=0;//Af，Ae是初始队列的头,尾。Bf，Be是合并后队列的头和尾
/*就是因为这个部分，所以我说了可以用两个队列（数组），一个存合并，一个存初始，然后疯狂删减，但是要注意的是
初始队列是在不停删，合并队列却在不停加，要注意好控制两个指针的位置，并且要关注，初始队列是可能被清空的，清
即跳出*/
/*
    if (n==1)return a[1];//其实一堆的话我不费力气的，但是我要以第一堆为基础！！他也肯定不会只给我一堆的对吧！
    a[1]=a[1]+a[2];//合并，第一堆等于前两堆之和！
    Af=3;//前两堆已经合并了，我让他从第三个开始！
    Ae=n;//然后在第n个结束！
    Bf=1;//合并队列现在什么都没有所以开始和结束都在“1”的位置上！
    Be=1;
    sum+=a[Be];//记录力气！
    while(Bf<n-1)
    {
        if((a[Af]<=a[Bf])&&(Af<=Ae))//我把合并后的这个值就直接记录一下，如果这个队列后面的值小于这两个值合并后的值！！
        {
            if ((a[Af+1]<a[Bf])&&(Af+1<=Ae))//如果后两个值都小于这个值，那么！！
            {
                a[++Be]=a[Af]+a[Af+1];//我下一步一定是让后两个值加在一起
                sum+=a[Be];//并且把两个值也都存起来
                Af=Af+2;//直接跳过这两个值再继续搜
            }
            else
            {
                a[++Be]=a[Af]+a[Bf];//如果只有后面的一个值小于合并后的这个值
                sum+=a[Be];//那么我就应该让合并后的值和后面的那个值加一起！！
                Af++;//然后初始数列没了一个值！
                Bf++;//合并后的数列也没了一个值!
            }
        }
        else//如果后面那个数比我大！！
        {
            if (((a[Af]<a[Bf+1])&&(Bf+1<=Be)&&(Af<=Ae))||((Bf==Be)&&(Af<=Ae)))//如果后面那个数只是比我合并完的其中一个数大！！
            {
                a[++Be]=a[Af]+a[Bf];//我就合并这个小于他数的和后面的值，
                sum+=a[Be];
                Af++;
                Bf++;
            }
            else//如果他大于两个合并后的值!!
            {
                a[++Be]=a[Bf]+a[Bf+1];//那我就合并这两个我合并后的值！！
                sum+=a[Be];
                Bf=Bf+2;//要注意因为合并了两个合并后的值！所以要+2！
            }
        }
    }
    return sum;//把力气输出来！！
}*/