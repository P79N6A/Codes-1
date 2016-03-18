#include<stdio.h>
#include<string.h>

void kmp_pre(char x[],int m,int next[])
{
int i,j;
j=next[0]=-1;
i=0;
while(i<m)
{
while(-1!=j && x[i]!=x[j])j=next[j];
next[++i]=++j;
}
}
/*
* kmpNext[]����˼�� next'[i]=next[next[...[next[i]]]] (ֱ��next'[i]<0����
x[next'[i]]!=x[i])
* ������Ԥ������Կ�һЩ
*/
void preKMP(char x[],int m,int kmpNext[])
{
int i,j;
j=kmpNext[0]=-1;
i=0;
while(i<m)
{
while(-1!=j && x[i]!=x[j])j=kmpNext[j];
if(x[++i]==x[++j])kmpNext[i]=kmpNext[j];
else kmpNext[i]=j;
}
}
/*
* ����x��y�г��ֵĴ����������ص�
*/
int next[10010];

int KMP_Count(char x[],int m,char y[],int n)
{//x��ģʽ���� y������
int i,j;
int ans=0;
//preKMP(x,m,next);
kmp_pre(x,m,next);
i=j=0;
while(i<n)
{
while(-1!=j && y[i]!=x[j])j=next[j];
i++;j++;
if(j>=m)
{
ans++;
j=next[j];
}
}
return ans;
}

char s[5100], p[5100];

int main()
{
    int t, n; scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase)
    {
        getchar();
        gets(s);
        scanf("%d", &n);
        printf("Case #%d:\n", kase);
        for (int i = 0; i < n; ++i)
        {
            getchar();
            gets(p);
            printf("%d\n", KMP_Count(p, strlen(p), s, strlen(s)));
        }
    }
    return 0;
}
