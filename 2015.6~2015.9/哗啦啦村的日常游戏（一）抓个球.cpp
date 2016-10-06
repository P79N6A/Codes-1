#include<iostream>
#include<cctype>
#include<cstdio>
#include<algorithm>
using namespace std;
double e[1011][1011];

double dfs(int w, int b)
{
    if(e[w][b] >= 0.0) return e[w][b];
    double ww = w, bb = b;
    double ret = ww / (ww + bb);
    //小彭玉拿了黑球。注意这里概率的计算，要将三者的概率一同相乘
    if( b >= 3)
        ret += bb / (ww + bb) * (bb - 1) / (ww + bb - 1) * (bb - 2) / (ww + bb - 2) * dfs(w, b - 3);
    //小彭玉拿了白球
    if( w >= 1 && b >= 2)
        ret += bb / (ww + bb) * (bb - 1) / (ww + bb - 1) * ww / (ww + bb - 2) * dfs(w - 1, b - 2);
    return e[w][b] = ret;
}

int main()
{
    int w, b; scanf("%d%d", &w, &b);
    for(int i = 0; i <= w; ++i)
        for(int j = 0; j <= b; ++j)
            e[i][j] = -1;
    e[0][0] = 0, e[0][1] = 0, e[1][0] = 1;
    printf("%.9f\n", dfs(w, b) );
	return 0;
}


