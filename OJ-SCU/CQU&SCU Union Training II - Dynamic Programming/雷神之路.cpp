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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

typedef vector<ll> vec;
typedef vector<vec> mat;

const int INF = 0x7f7f7f7f;
const int MAXN = 5e2 + 111;
const int mod = 1e9 + 7;

mat mul(mat A, mat B) {
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int k = 0; k < B.size(); ++k) {
            for (int j = 0; j < B[0].size(); ++j) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

mat mpow(mat A, ll n) {
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); ++i) B[i][i] = 1;
    while (n > 0) {
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

ll pos[MAXN];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ll n;
    int t, m; scanf("%d", &t);
    while (t --){
        scanf("%lld%d", &n, &m);
        mat C(3, vec(1));
        C[0][0] = 0, C[1][0] = 0, C[2][0] = 1;
        for (int i = 0; i < m; ++i) {
            scanf("%lld", &pos[i]);
        }
        sort(pos, pos + m);
        mat A(3, vec(3));
        mat B(3, vec(3));
        A[0][0] = 0, A[0][1] = 1, A[0][2] = 0;
        A[1][0] = 0, A[1][1] = 0, A[1][2] = 1;
        A[2][0] = 1, A[2][1] = 1, A[2][2] = 1;
        B[0][0] = 0, B[0][1] = 1, B[0][2] = 0;
        B[1][0] = 0, B[1][1] = 0, B[1][2] = 1;
        B[2][0] = 0, B[2][1] = 0, B[2][2] = 0;
        ll last = 0;
        for (int i = 0; i < m; ++i) {
            C = mul(B, mul(mpow(A, pos[i] - last - 1), C));
            last = pos[i];
        }
        if (last < n) {
            C = mul(mpow(A, n - last), C);
        }
        printf("%d\n", C[2][0]);
    }
    return 0;
}
