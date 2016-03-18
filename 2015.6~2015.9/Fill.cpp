//Orz
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN = 203;
int cap[3], t, d, ans[MAXN];
bool vis[MAXN][MAXN]; //ö������״̬���ɣ�vis[i][j]����a: i  b: j 

struct State{
	int v[3];
	int w;
	bool operator < (const State& t)const
	{
		return w > t.w;
	}
};

void Update(State &t)
{
	for( int i = 0 ; i < 3 ; ++i )
	{
		int d = t.v[i];
		if( ans[d] == -1 || ans[d] > t.w ) ans[d] = t.w;
	}
}

void bfs()
{
	priority_queue< State > q;
	memset( vis , 0 , sizeof vis );
	memset( ans , -1 , sizeof ans );
	State sta;
	sta.v[0] = sta.v[1] = sta.w = 0; //��ʼ״̬ 
	sta.v[2] = cap[2];
	q.push( sta );
	vis[0][0] = 1;
	
	while( !q.empty() ) //ÿ��ȡ��ˮ�����ٵ��Ǹ�״̬���и��� 
	{
		State now = q.top(); q.pop(); Update( now );
		if( ans[d] != -1 ) return;
		for( int i = 0 ; i < 3 ; ++i ) //��״̬�ɸ��µ�������״̬.��i�е�ˮ����j�� ���������ѭ�������ڲ�ѭ���� 
		{
			for( int j = 0 ; j < 3 ; ++j )
			{
				State cur = now ;
				int &x = cur.v[i] , &y = cur.v[j] ;
				if( i != j && x && y < cap[j] ) //x��ˮ��y�ܷ�ˮ 
				{
					int pour = min( x , cap[j] - y );
					x -= pour;
					y += pour;
					cur.w += pour;
					if( !vis[cur.v[0]][cur.v[1]] ) //cur.v[0] cur.v[1]���ŵ�ˮ�Ľ����ǲ��ϱ仯�� 
					{
						vis[cur.v[0]][cur.v[1]] = 1;
						q.push(cur);
					}
				}
			}
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
#endif
	scanf( "%d" , &t );
	while(t --)
	{
		for ( int i = 0 ; i < 3 ; ++i ) scanf( "%d" , cap + i );
		scanf( "%d" , &d );
		bfs();
		for( int i = d ; i >= 0 ; --i )
		{
			if( ans[i] != -1 ){ printf( "%d %d\n" , ans[i] , i ); break;}
		}
	} 
	return 0;
}

