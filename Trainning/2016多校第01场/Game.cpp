/*
  首先不管守卫，把所有起始位置能放置路人的位置的
  最短路和求出来。这时会把到守卫的位置算入到最短
  路内，那么碰到守卫就减去守卫能到达的所有最短路，
  这时又重复计算了守卫间的距离，所以要补回来。哈
  哈，不细说，自己画图去~通过画图发现，最短路其实
  就是以这个点为中心类似涟漪，所以可以分四个部分
  求。而守卫，只有连续守卫位置增长的，或者连续下降
  的才会影响答案。
  标程求最短路的方法劲啊，根据最短路等于
  |x1 - x2| + |y1 - y2|，按行进行求解，行1和行2的
  空位间最短路距离至少有贡献|x1 - x2|，所以把距离
  乘以空格乘积个数即可
 */
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pr(x) cout << #x << " = " << (x) << "  ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1111;

int n, m;
char mp[MAXN][MAXN];
double px[MAXN], py[MAXN];
int posx[MAXN], cnt = 0, posy[MAXN];

double num[5];
/* 四个部分求解
    |
  - 0 -
    |
 */
inline double cal(double x, double y) {
    double ret = 0;
    num[4] = num[0] = x, num[1] = y, num[2] = n - x - 1, num[3] = m - y - 1;
    for (int i = 0; i < 4; ++i) {
        double sum = (1 + num[i]) * num[i] / 2;
        double add = num[i], len = num[i + 1];
        ret += sum + sum * len + add * ((1 + len) * len / 2);
    }
    return ret;
}

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        cnt = 0;
        memset(posx, -1, sizeof posx);
        memset(posy, -1, sizeof posy);
        for (int i = 0; i < n; ++i) {
            scanf("%s", mp[i]);
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == 'G') {
                    px[cnt] = i, py[cnt++] = j;
                    posx[i] = j, posy[j] = i;
                    break;
                }
            }
        }
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] != 'G')
                    sum += cal(i, j);
                else sum -= cal(i, j);
            }
        }
        for (int i = 0; i < cnt; ++i) {
            for (int j = 0; j < cnt; ++j) {
                sum += abs(px[i] - px[j]) + abs(py[i] - py[j]);
            }
        }
		// 连续增或减才会影响，记得考虑行和列两种情况，以下为行
        for (int i = 0; i < n; ++i) {
            if (posx[i] == -1) continue;
            sum += 4 * (m - posx[i] - 1) * posx[i];
            int pp = posx[i], pre = 0;
            for (int j = i + 1; j < n; ++j) {
                if (posx[j] == -1) break;
                if (posx[j] < pp && pre != 2) {
                    sum += (m - posx[i] - 1) * posx[j] * 4;
                    pp = posx[j];
                    pre = 1;
                }
                else if (posx[j] > pp && pre != 1) {
                    sum += posx[i] * (m - posx[j] - 1) * 4;
                    pp = posx[j];
                    pre = 2;
                }
                else break;
            }
        }
		// 以下为列
        for (int i = 0; i < m; ++i) {
            if (posy[i] == -1) continue;
            sum += 4 * (n - posy[i] - 1) * posy[i];
            int pp = posy[i], pre = 0;
            for (int j = i + 1; j < m; ++j) {
                if (posy[j] == -1) break;
                if (posy[j] < pp && pre != 2) {
                    sum += (n - posy[i] - 1) * posy[j] * 4;
                    pp = posy[j];
                    pre = 1;
                }
                else if (posy[j] > pp && pre != 1) {
                    sum += posy[i] * (n - posy[j] - 1) * 4;
                    pp = posy[j];
                    pre = 2;
                }
                else break;
            }
        }
        double tol = n * m - cnt;
        printf("%.4f\n", sum / (tol * tol));
    }
    return 0;
}
