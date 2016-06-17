#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int VM=30;
const int INF=0x3f3f3f3f;

struct Edge{
    int to,nxt;
    int cap;
}edge[2010];

int n,cnt,head[VM],ans;
int need[VM],have[VM],dis[VM],Count[VM],vis[VM];    //// 每个节点的dis[i]表示的含义为到第 i 个小时时间段已经雇佣的员工数量
  //need[i]表示 i 时间段一共雇佣了多少员工    have[i]表示 i 时段有多少人申请工作

void addedge(int cu,int cv,int cw){
    edge[cnt].to=cv;    edge[cnt].cap=cw;   edge[cnt].nxt=head[cu];
    head[cu]=cnt++;
}

void build(int lim){    // lim表示欲招的员工个数
    cnt=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=24;i++){
        addedge(i-1,i,have[i]);     // need[i] - need[i-1] <= hav[i]， 雇佣的人数少于申请者
        addedge(i,i-1,0);           // need[i-1] - need[i] <= 0   即  need[i] - need[i-1] >= 0   每个小时内雇佣的人数应该是个非负数
    }
    for(int i=1;i<8;i++)    // 由于无法直接得到从前一天的后几小时到当天前几小时的雇佣人数，所以反面求解
        addedge(i,24+i-8,lim-need[i]);  // need[24+i-8] - need[i] <= lim-need[i]
    for(int i=8;i<=24;i++)  // 前8小时内雇佣人数应该大于等于需求量
        addedge(i,i-8,-need[i]);    // need[i] - need[i-8] >= need[i] ,即：need[i-8]-need[i]<=-need[i]
    addedge(24,0,-lim); // need[24] - need[0] >= lim,即：need[0]-need[24]<=-lim  表示至少为lim个员工，这样就能够看在最好情况下能不能取到这个最小值
}

int SPFA(int lim){
    queue<int> q;
    while(!q.empty())
        q.pop();
    for(int i=0;i<VM;i++){
        dis[i]=INF;
        vis[i]=0;
        Count[i]=0;
    }
    dis[24]=0;  vis[24]=1;  Count[24]=1;
    q.push(24);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(Count[u]>25)
            return 0;
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].cap){
                dis[v]=dis[u]+edge[i].cap;
                if(!vis[v]){
                    vis[v]=1;
                    Count[v]++;
                    q.push(v);
                }
            }
        }
    }
    return dis[0]=-lim;
}

int BinSearch(int l,int r){
    ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;   // mid 表示一共能够雇佣的员工数量
        build(mid);
        if(SPFA(mid)){
            ans=mid;
            r=mid-1;    //因为此题要求的是最小的雇佣人数，所以得判断r=mid-1使否满足题意，使之越来越小
        }else
            l=mid+1;
    }
    return ans!=-1;
}

int main(){

    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--){
        memset(have,0,sizeof(have));
        for(int i=1;i<=24;i++)  //0时刻申请将工作在第一个小时
            scanf("%d",&need[i]);
        scanf("%d",&n);
        int x;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            have[x+1]++;    //这样做是为了从1～24计算
        }
        if(BinSearch(0,n))
            printf("%d\n",ans);
        else
            printf("No Solution\n");
    }
    return 0;
}
