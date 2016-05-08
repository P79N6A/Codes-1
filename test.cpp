#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

const int INF = 0x3f3f3f3f;

const int Max = 550;

typedef struct node
{
    int v,w,next;
}edge;

edge e[Max*Max];

int H[Max],top;


int Dis[Max];

int num[Max],Num[Max][2];

int pre[Max];

bool vis[Max];

int n,m,s,t;

int a[Max];

void AddEdge(int u,int v,int w)
{
    e[top].v = v; e[top].w = w;

    e[top].next =  H[u] ;  H[u] = top++;


    e[top].v = u; e[top].w = w;

    e[top].next =  H[v] ;  H[v] = top++;
}

void SPFA()
{
    memset(Dis,INF,sizeof(Dis));

    for(int i = 0;i<n;i++)
    {
        num[i] = a[i];

        pre[i] = -1;

        Num[i][0] = Num[i][1] = 0;

        vis[i] = false;
    }

    vis[s] = true;

    Dis[s] = 0;

    queue<int>Q;

    Num[s][0] = 1;

    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front();

        Q.pop();

        for(int i = H[u];~i;i= e[i].next)
        {
            int v = e[i].v;

            if(Dis[v]>Dis[u]+e[i].w)
            {
                Dis[v]  =Dis[u]+e[i].w;

                Num[v][1] = Num[v][0];
                Num[v][0] = Num[u][0];

                num[v] = a[v]+num[u];

                pre[v] = u;

                if(!vis[v])
                {
                    vis[v] = true;

                    Q.push(v);
                }
            }
            else if(Dis[v]==Dis[u]+e[i].w)
            {
                Num[v][1] = Num[v][0];
                Num[v][0] += (Num[u][0]-Num[u][1]);


                if(num[v]<num[u]+a[v])
                {
                    num[v] = num[u]+a[v];

                    pre[v] = u;
                }
                if(!vis[v])
                {
                    vis[v] = true;

                    Q.push(v);
                }

            }
        }

        vis[u]= false;
    }


}

int main()
{
    int u,v,w;

    while(~scanf("%d %d %d %d",&n,&m,&s,&t))
    {
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        top =0 ;

        memset(H,-1,sizeof(H));

        for(int i = 0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);

            AddEdge(u,v,w);
        }

        SPFA();

        printf("%d %d\n",Num[t][0],num[t]);

        stack<int>S;

        for(int i = t ;~i;i  = pre[i])
        {
            S.push(i);
        }
        bool flag = false;

        while(!S.empty())
        {
            if(!flag) flag= true;

            else printf(" ");

            printf("%d",S.top());

            S.pop();
        }
        printf("\n");
    }
    return 0;
}
