#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 1100

int add=0;

void convert(char *a,int lenth)
{
    char t;
    for(int i=0;i<lenth/2;i++){
        t=a[i];
        a[i]=a[lenth-i-1];
        a[lenth-i-1]=t;
    }
}

bool exceed(char a,char b)
{
    if(a+b+add-2*'0'>9)
        return true;
    else return false;
}

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,k=0;
    char num1[maxn],num2[maxn],sum[maxn];
    cin>>t;
    while(t--)
    {
        add=0;
        k++;
        memset(num1,0,sizeof num1);
        memset(num2,0,sizeof num2);
        memset(sum,0,sizeof sum);
        scanf("%s%s",num1,num2);
        int len1=strlen(num1),len2=strlen(num2),len3;
        printf("Case %d:\n",k);
        printf("%s + %s = ",num1,num2);
        convert(num1,len1);
        convert(num2,len2);
        //cout<<num1<<' '<<num2<<endl;
        if(len2>len1){
            for(int i=len1;i<len2;i++)
                num1[i]='0';
            len3=len2;
        }
        else {
            for(int i=len2;i<len1;i++)
                num2[i]='0';
            len3=len1;
        }
        for(int i=0;i<len3;i++){
            if(exceed(num1[i],num2[i])){
                sum[i]=num1[i]+num2[i]+add-'0'-10;
                add=1;
            }
            else{
                sum[i]=add+num1[i]+num2[i]-'0';
                add=0;
            }
        }
        if(add==1){
            sum[len3]='1';
            len3++;
        }
        convert(sum,len3);
        cout<<sum<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}