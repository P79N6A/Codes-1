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
const int MAXN = 5e5 + 111;

char name[MAXN][11];
int offs[MAXN];
int candy[MAXN];

inline void init(int n) {
    fill(candy, candy + n, 1);
    for (int i = 2; i < n; ++i) {
        if (candy[i] == 1) {
            for (int j = i; j < n; j += i) {
                int k = 0;
                for (int temp = j; temp % i == 0; temp /= i, ++k);
                candy[j] *= (k + 1);
            }
        }
    }
}

template<class T>
class BIT {
public:
    T bit[MAXN];
    int n;
    void init(int n) {
        this->n = n;
        memset(bit, 0, sizeof bit);
    }
    T getsum(int x) {
        T ret = 0;
        for (int i = x; i > 0; i -= i & -i) ret += bit[i];
        return ret;
    }
    void add(int x, T val) {
        for (int i = x; i <= n; i += i & -i) bit[i] += val;
    }
    int search(int id) {
        int l = 0, r = n, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            int sum = getsum(mid);
            if (sum <= id) {
                ans = mid;
                l = mid + 1;
            }
            else if (sum > id) {
                r = mid - 1;
            }
        }
        return ans;
    }
};

BIT<int> bt;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, k;
    init(MAXN - 100);
    while (~scanf("%d%d", &n, &k)) {
        bt.init(n);
        --k;
        for (int i = 0; i < n; ++i) {
            scanf("%s%d", &name[i], &offs[i]);
            bt.add(i + 1, 1);
        }
        int id = k, ans = -1;
        for (int i = 0; i < n; ++i) {
            if (ans < candy[i + 1]) {
                ans = candy[i + 1];
                id = k;
            }
            bt.add(k + 1, -1);
            if (i < n - 1) {
                int lef = n - i - 1;
                // 下一个孩子前面有多少个孩子
                int tid = bt.getsum(k) + offs[k] - (offs[k] > 0);
                tid = (tid % lef + lef) % lef;
                k = bt.search(tid);
            }
        }
        printf("%s %d\n", name[id], ans);
    }
    return 0;
}
