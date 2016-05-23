#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
#define MAXN 30
#define INF 0x7FFFFFFF

int n , k , ans , cnt;/*�ߵĳ���n��k�� , cnt��ʾ�м�����*/
int vis[MAXN];/*��ǵ�i�Ƿ������������*/
int mark[MAXN];/*��prime�㷨������õ�*/
int pre[MAXN];/*��i��ǰ���ڵ�*/
int father[MAXN];/*�������и��ڵ�ı��*/
int best[MAXN];/*��¼��i�����Ƶ㲢�Һ����Ƶ�û�й��������ߵĵ�ı��*/
int edge[MAXN][MAXN];/*������ʾ���Ƿ�������������*/
int G[MAXN][MAXN];/*��������֮���Ȩֵ*/
int lowcost[MAXN];
map<string , int>m;

/*��ʼ��G*/
void init(){
   for(int i = 0 ; i < MAXN ; i++){
      for(int j = 0 ; j < MAXN ; j++)
         G[i][j] = INF;
   }
}

/*dfs��һ����ͨ��֧����ĵ�ȫ��ָ��s*/
void dfs(int s){
   for(int i = 1 ; i <= cnt ; i++){
      if(mark[i] && edge[i][s]){
        father[i] = s;
        mark[i] = 0;
        dfs(i);
      }
   }
}

/*prime�㷨*/
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
   /*һ�����ҵ�һ����СȨֵ�ı߰Ѹ���ͨ�������ӵ����Ƶ�1*/
   int min = INF;
   int root = -1;/*Ҫ��1�����ӵĵ�*/
   for(int i = 1 ; i <= cnt ; i++){
      if(mark[i] && G[i][1] < min){
        min = G[i][1];
        root = i;
      }
   }
   /*�ѵ�ǰ����ͨ*/
   mark[root] = 0;
   dfs(root);
   father[root] = 1;
   return sum+min;
}

/*��best���麯��,���s-1·����Ȩֵ���ıߵ��յ�*/
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
    vis[1] = 1;/*��1����㵱�����Ƶ�*/
    int num = 0;/*��1���Ƶ�ȥ���Ժ����ͨ��֧�ĸ���*/
    ans = 0;

    /*������Сnum��������*/
    for(int i = 1 ; i <= cnt ; i++){
       if(!vis[i]){
         num++;
         ans += prime(i);
       }
    }

    /*����m������������->k��������*/
    int minAdd;/*����һ���߸ı��Ȩֵ��С*/
    int change;/*��¼��·��Ҫɾ���ıߵ��յ�*/
    /*ѭ��k-num��*/
    for(int i = num+1 ; i <= k && i <= cnt ; i++){
       memset(best , -1 , sizeof(best));/*��ʼ��Ϊ-1*/
       /*���best����*/
       for(int j =1 ; j <= cnt ; j++){
          if(best[j] == -1 && father[j] != 1)
            Best(j);
       }
       minAdd = INF;/*��ʼ��ΪINF*/
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
       if(minAdd >= 0)/*Ҫ������һ��*/
         break;
       ans += minAdd;
       int a = best[change];
       int b = father[change];
       G[a][b] = G[b][a] = INF;/*����һ����ȥ�����Ǹ�ֵΪINF*/
       father[a] = 1;/*��a�ĸ��׽ڵ�ָ��Ϊ���Ƶ�1*/
       G[a][1] = G[1][a] = G[change][1];/*�����ӵ�һ���ߵ�Ȩֵ*/
       G[1][change] = G[change][1] = INF;
    }
}

int main(){
   int v;
   string str1 , str2;
   m.clear();
   m["Park"] = 1;
   cnt = 1;/*��ʼ����һ����*/
   init();/*��ʼ��*/
   scanf("%d" , &n);
   for(int i = 0 ; i < n ; i++){
      cin>>str1>>str2>>v;
      int a = m[str1];
      int b = m[str2];
      if(!a)
        m[str1] = a = ++cnt;
      if(!b)
        m[str2] = b = ++cnt;
      if(G[a][b] > v)/*a b Ϊ��ı�ţ��������治��ֱ�Ӱ�m[str1] = 1*/
        G[a][b] = G[b][a] = v;
   }
   scanf("%d" , &k);
   solve();
   printf("Total miles driven: %d\n" , ans);
   return 0;
}
