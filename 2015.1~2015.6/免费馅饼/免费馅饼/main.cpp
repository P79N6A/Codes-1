 #include <iostream>
 #include <cstdio>
 #include <cstring>
 
 using namespace std;
 const int MAXN = 1e5 + 111;
 int pi[MAXN][15];
 
 int main()
 {
 int n;
 while(scanf("%d", &n) && n)
 {
 memset(pi, 0, sizeof pi);
 int x, t = 0, mt = 0;
 for (int i = 0; i < n; ++i)
 {
 scanf("%d %d", &x, &t);
 ++x;
 ++pi[t][x];
 if (mt < t)
 mt = t;
 }
 for (int i = mt - 1; i >= 0; --i)
 {
 for (int j = 1; j <= 11; ++j)
 {
 pi[i][j] += max(max(pi[i + 1][j - 1], pi[i + 1][j]), pi[i + 1][j + 1]);
 }
 }
 printf("%d\n", pi[0][6]);
 }
 return 0;
 }