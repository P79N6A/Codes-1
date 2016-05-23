#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
#define MAXN 30
#define INF 0x7FFFFFFF

int n , k , ans , cnt;/*边的长度n和k度 , cnt表示有几个点*/
int vis[MAXN];/*标记点i是否加入了生成树*/
int mark[MAXN];/*在prime算法里面会用到*/
int pre[MAXN];/*点i的前驱节点*/
int father[MAXN];/*生成树中父节点的编号*/
int best[MAXN];/*记录点i到限制点并且和限制点没有关联的最大边的点的编号*/
int edge[MAXN][MAXN];/*用来表示边是否已在生成树中*/
int G[MAXN][MAXN];/*保存两点之间的权值*/
int lowcost[MAXN];
map<string , int>m;

/*初始化G*/
void init(){
   for(int i = 0 ; i < MAXN ; i++){
      for(int j = 0 ; j < MAXN ; j++)
         G[i][j] = INF;
   }
}

/*dfs把一个连通分支里面的点全部指向s*/
void dfs(int s){
   for(int i = 1 ; i <= cnt ; i++){
      if(mark[i] && edge[i][s]){
        father[i] = s;
        mark[i] = 0;
        dfs(i);
      }
   }
}

/*prime算法*/
int prime(int s){
   int sum , pos;
   memset(mark , 0 ,sizeof(mark));
   vis[s] = mark[s] = 1;
   sum = 0;
   for(int i = 1 ; i <= cnt ; i++){
      lowcost[i] = G[s][i];
      pre[i] = s;
   }
   for(int i = 1 ; i <= cnt ; i++){
      pos = -1;
      for(int j = 1 ; j <= cnt ; j++){
         if(!vis[j] && !mark[j]){
           if(pos == -1 || lowcost[j] < lowcost[pos])
             pos = j;
         }
      }
      if(pos == -1)
        break;
      vis[pos] = mark[pos] = 1;
      edge[pre[pos]][pos] = edge[pos][pre[pos]] = 1;
      sum += G[pre[pos]][pos];
      for(int j = 1 ; j <= cnt ; j++){
         if(!vis[j] && !mark[j]){
           if(lowcost[j] > G[pos][j]){
             lowcost[j] = G[pos][j];
             pre[j] = pos;
           }
         }
      }
   }
   /*一下是找到一条最小权值的边把该连通分量连接到限制点1*/
   int min = INF;
   int root = -1;/*要和1点连接的点*/
   for(int i = 1 ; i <= cnt ; i++){
      if(mark[i] && G[i][1] < min){
        min = G[i][1];
        root = i;
      }
   }
   /*把当前的连通*/
   mark[root] = 0;
   dfs(root);
   father[root] = 1;
   return sum+min;
}

/*求best数组函数,求解s-1路径上权值最大的边的终点*/
int Best(int s){
    if(father[s] == 1)
      return -1;
    if(best[s] != -1)
      return best[s];
    int tmp = Best(father[s]);
    if(tmp != -1 && G[father[tmp]][tmp] > G[father[s]][s])
      best[s] = tmp;
    else
      best[s] = s;
    return best[s];
}

void solve(){
    memset(father , -1 , sizeof(father));
    memset(vis , 0 , sizeof(vis));
    memset(edge , 0 , sizeof(edge));
    vis[1] = 1;/*把1这个点当成限制点*/
    int num = 0;/*把1限制点去掉以后的连通分支的个数*/
    ans = 0;

    /*先求最小num度限制树*/
    for(int i = 1 ; i <= cnt ; i++){
       if(!vis[i]){
         num++;
         ans += prime(i);
       }
    }

    /*再由m度限制生成树->k度生成树*/
    int minAdd;/*增加一条边改变的权值大小*/
    int change;/*记录回路上要删除的边的终点*/
    /*循环k-num次*/
    for(int i = num+1 ; i <= k && i <= cnt ; i++){
       memset(best , -1 , sizeof(best));/*初始化为-1*/
       /*求出best数组*/
       for(int j =1 ; j <= cnt ; j++){
          if(best[j] == -1 && father[j] != 1)
            Best(j);
       }
       minAdd = INF;/*初始化为INF*/
       for(int j = 1 ; j <= cnt ; j++){
          if(G[1][j] != INF && father[j] != 1){
            int a = best[j];
            int b = father[best[j]];
            int tmp = G[1][j]-G[a][b];
            if(tmp < minAdd){
              minAdd = tmp;
              change = j;
            }
          }
       }
       if(minAdd >= 0)/*要加上这一句*/
         break;
       ans += minAdd;
       int a = best[change];
       int b = father[change];
       G[a][b] = G[b][a] = INF;/*把这一条边去掉就是赋值为INF*/
       father[a] = 1;/*把a的父亲节点指向为限制点1*/
       G[a][1] = G[1][a] = G[change][1];/*新增加的一条边的权值*/
       G[1][change] = G[change][1] = INF;
    }
}

int main(){
   int v;
   string str1 , str2;
   m.clear();
   m["Park"] = 1;
   cnt = 1;/*初始化有一个点*/
   init();/*初始化*/
   scanf("%d" , &n);
   for(int i = 0 ; i < n ; i++){
      cin>>str1>>str2>>v;
      int a = m[str1];
      int b = m[str2];
      if(!a)
        m[str1] = a = ++cnt;
      if(!b)
        m[str2] = b = ++cnt;
      if(G[a][b] > v)/*a b 为点的编号，所以上面不能直接把m[str1] = 1*/
        G[a][b] = G[b][a] = v;
   }
   scanf("%d" , &k);
   solve();
   printf("Total miles driven: %d\n" , ans);
   return 0;
}
