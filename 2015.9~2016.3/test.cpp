//��n������,si,ni,ei,ti��ʾ��i���������ʼʱ�䣬��Ҫ�������⴮�ĸ���
//��ֹʱ�䣬ÿ�����⴮����ʱ��
//�����⴮��ʱ�䲻��Ҫ��������ÿ�����⴮���Խ���ֳ�k������һ�𿾣��Ӷ�����һ�����⴮��ʱ��Ϊti/k;
//���ܷ������������
//�����hdu3572��Щ��
//ֻ������ʱ��ĳ���1 <= si < ei <= 1,000,000�ܴ�
//���Խ�ʱ�仮��Ϊʱ��Σ��仮�ֵĶ������Ϊ2*n-1��
//��ÿ��ʱ��ο���һ���㣬����ÿ����������ʼʱ�����ֹʱ��������ʱ�������ȨֵΪ
//(b[i].ei - b[i].si + 1)*m�ı�
//��һ������Դ������ȨֵΪni*ti�ıߣ���ÿ��ʱ����򳬼��������ȨֵΪ(b[i].ei - b[i].si + 1)*m�ı�
//�ж����Ƿ���������
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std ;
const int maxn = 1010 ;
const int inf = 0x7fffffff ;
int st = 0 , en = 1001 ;   int cnt = 1 ;
int dis[maxn],head[maxn] ,nedge ;int n , m ;
int s[maxn] , e[maxn] , t[maxn] ,ni[maxn] ;
struct node
{
    int si ,ei ;
    bool operator < (const node tmp)const
    {
        if(tmp.si == si)
        return ei < tmp.ei ;
        return si < tmp.ei ;
    }
    bool operator == (const node tmp)const
    {
        return ((tmp.si == si)&&(tmp.ei == ei)) ;
    }
}a[maxn] ,b[maxn<<1];
struct Edge
{
    int v , w ;
    int next ;
}edge[maxn<<1] ;
void addedge(int u , int v ,int w)
{
    edge[nedge].v = v ;
    edge[nedge].w = w ;
    edge[nedge].next = head[u] ;
    head[u] = nedge++ ;
    edge[nedge].v = u ;
    edge[nedge].w = 0 ;
    edge[nedge].next = head[v] ;
    head[v] = nedge++ ;
}
bool bfs()
{
    memset(dis , -1 , sizeof(dis)) ;
    queue<int> que ;
    que.push(st) ;
    dis[st] = 0 ;
    while(que.size())
    {
        int u = que.front() ; que.pop() ;
        for(int i = head[u] ; i != -1 ;i = edge[i].next)
        {
            int v = edge[i].v ;
            if(dis[v] < 0 && edge[i].w > 0)
            {
                dis[v] = dis[u] + 1 ;
                que.push(v) ;
            }
        }
    }
    if(dis[en] > 0)return true ;
    return false ;
}
int dfs(int u , int mx)
{
    if(u == en)
    return mx ;
    int ans = 0 ;
    int a ;
    for(int i = head[u] ;i != -1 ;i = edge[i].next)
    {
        int v = edge[i].v ;
        if(dis[v] == dis[u] + 1 && edge[i].w > 0 && (a = dfs(v , min(mx,edge[i].w))))
        {
            ans += a ;
            mx -= a ;
            edge[i].w -= a ;
            edge[i^1].w += a ;
            if(mx == 0)
            break ;
        }
    }
    if(ans == 0)dis[u] = -1 ;
    return ans ;
}
int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    //freopen("in.txt" , "r" , stdin) ;
    while(~scanf("%d%d" , &n , &m))
    {
        memset(head , -1 , sizeof(head)) ;
        nedge = 0 ;
        int sum = 0 ;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d%d" , &s[i] ,&ni[i] , &e[i] , &t[i]) ;
            s[i]++ ;
            sum += ni[i]*t[i];
            a[i].si = s[i] , a[i].ei = e[i] ;
        }
        sort(a + 1 , a + 1 + n) ;
        int len = unique(a+1 , a+1+n) - (a+1) ;
        b[1].si = 1 ; b[1].ei = maxn*maxn ;
        cnt = 1;
        for(int i = 1;i <= len;i++)
        {
            for(int j = 1;j <= cnt;j++)
            if(a[i].si > b[j].si && a[i].si <= b[j].ei)
            {
                b[++cnt].si = a[i].si ;
                b[cnt].ei = b[j].ei ;
                b[j].ei = a[i].si - 1 ;
            }
            for(int j = 1;j <= cnt;j++)
            {
                if(b[j].si <= a[i].ei && a[i].ei < b[j].ei)
                {
                    b[++cnt].si = b[j].si ;
                    b[cnt].ei = a[i].ei ;
                    b[j].si = a[i].ei + 1 ;
                }
            }
        }
        for(int i = 1;i <= cnt;i++)
           for(int j = 1;j <= n;j++)
           {
               if(s[j] <= b[i].si && b[i].ei <= e[j])
               addedge(j , 200 + i , (b[i].ei - b[i].si + 1)*m) ;
           }
        for(int i = 1;i <= n;i++)
        addedge(st,i ,ni[i]*t[i]) ;
        for(int i = 1;i <= cnt;i++)
        addedge(i+200 , en , (b[i].ei - b[i].si + 1)*m);
        int ans = 0 ;int res ;
        while(bfs())
          while(res = dfs(st , inf))
          ans += res;
        if(ans == sum)puts("Yes");
        else puts("No");
     }
}
