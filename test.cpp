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
int need[VM],have[VM],dis[VM],Count[VM],vis[VM];    //// ÿ���ڵ��dis[i]��ʾ�ĺ���Ϊ���� i ��Сʱʱ����Ѿ���Ӷ��Ա������
  //need[i]��ʾ i ʱ���һ����Ӷ�˶���Ա��    have[i]��ʾ i ʱ���ж��������빤��

void addedge(int cu,int cv,int cw){
    edge[cnt].to=cv;    edge[cnt].cap=cw;   edge[cnt].nxt=head[cu];
    head[cu]=cnt++;
}

void build(int lim){    // lim��ʾ���е�Ա������
    cnt=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=24;i++){
        addedge(i-1,i,have[i]);     // need[i] - need[i-1] <= hav[i]�� ��Ӷ����������������
        addedge(i,i-1,0);           // need[i-1] - need[i] <= 0   ��  need[i] - need[i-1] >= 0   ÿ��Сʱ�ڹ�Ӷ������Ӧ���Ǹ��Ǹ���
    }
    for(int i=1;i<8;i++)    // �����޷�ֱ�ӵõ���ǰһ��ĺ�Сʱ������ǰ��Сʱ�Ĺ�Ӷ���������Է������
        addedge(i,24+i-8,lim-need[i]);  // need[24+i-8] - need[i] <= lim-need[i]
    for(int i=8;i<=24;i++)  // ǰ8Сʱ�ڹ�Ӷ����Ӧ�ô��ڵ���������
        addedge(i,i-8,-need[i]);    // need[i] - need[i-8] >= need[i] ,����need[i-8]-need[i]<=-need[i]
    addedge(24,0,-lim); // need[24] - need[0] >= lim,����need[0]-need[24]<=-lim  ��ʾ����Ϊlim��Ա�����������ܹ��������������ܲ���ȡ�������Сֵ
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
        int mid=(l+r)>>1;   // mid ��ʾһ���ܹ���Ӷ��Ա������
        build(mid);
        if(SPFA(mid)){
            ans=mid;
            r=mid-1;    //��Ϊ����Ҫ�������С�Ĺ�Ӷ���������Ե��ж�r=mid-1ʹ���������⣬ʹ֮Խ��ԽС
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
        for(int i=1;i<=24;i++)  //0ʱ�����뽫�����ڵ�һ��Сʱ
            scanf("%d",&need[i]);
        scanf("%d",&n);
        int x;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            have[x+1]++;    //��������Ϊ�˴�1��24����
        }
        if(BinSearch(0,n))
            printf("%d\n",ans);
        else
            printf("No Solution\n");
    }
    return 0;
}
