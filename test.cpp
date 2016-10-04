#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 400010;
#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << " " << endl;

int n, m, cnt, tot;
int sta[maxn], pre[maxn];
char t[10];
string emp[maxn];
map<string, int> mp;

int low(int x) {
    return x & (-x);
}

struct Bit {
    int a[100000];
    void clr() {
        memset(a, 0, sizeof(a));
    }
    void add(int pos, int x) {
        for(int i = pos; i <= 70010; i = i + low(i))
            a[i] += x;
    }
    int sum(int pos) {
        int ans = 0;
        for(int i = pos; i > 0; i = i - low(i))
            ans = ans + a[i];
        return ans;
    }
}bit;

struct Node {
    int id, movt, time, kind, tobit;
}node[maxn];

struct Qur {
    int id, movt, time, kind, toqur;
    bool operator < (const Qur& rh) const {
        if(movt == rh.movt) return time > rh.time;
        return movt > rh.movt;
    }
}qur[maxn];

void init() {
    int num = n;
    int hefa = n * 0.2;
    int person = 0;
    for(int i = 1; i < tot; i++) {
        int id = qur[i].toqur;
        node[id].tobit = i;
        if(qur[i].kind == 2) continue;
        person++;
        pre[qur[i].id] = i;
        if(person <= hefa) sta[qur[i].id] = 1;
        bit.add(i, 1);
    }
}

int work(int hefa) {
    int l = 0, r = 70000;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        int num = bit.sum(mid);
        if(num >= hefa) r = mid;
        else l = mid;
    }
    return r;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\Íõ³½³½\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\Íõ³½³½\\Desktop\\out.txt","w",stdout);
    #endif // LOCAL
    while(cin >> n) {
        cnt = 0;
        bit.clr();
        mp.clear();
        for(int i = 1; i <= n; i++) {
            string s; cin >> s;
            int id;
            if(mp[s] == 0) {
                mp[s] = cnt;
                emp[cnt++] = s;
            }
            id = mp[s];
            node[i].id = id;
            node[i].time = i;
            node[i].kind = 1;
            cin >> node[i].movt;
        }
        cin >> m;
        for(int i = 1; i <= m; i++) {
            int id;
            string s;
            scanf("%s", t);
            cin >> s;
            if(mp[s] == 0) {
                mp[s] = cnt;
                emp[cnt++] = s;
            }
            id = mp[s];
            if(t[0] == '+') {
                node[n + i].id = id;
                node[n + i].time = n + i;
                node[n + i].kind = 2;
                cin >> node[n + i].movt;
            }
            else {
                node[n + i].id = id;
                node[n + i].time = n + i;
                node[n + i].kind = 3;
                node[n + i].movt = -1;
            }
        }
        tot = 1;
        for(int i = 1; i <= n + m; i++) {
            if(node[i].kind == 3) continue;
            qur[tot].id = node[i].id;
            qur[tot].kind = node[i].kind;
            qur[tot].movt = node[i].movt;
            qur[tot].time = node[i].time;
            qur[tot].toqur = i;
            tot++;
        }
        sort(qur + 1, qur + tot);
        memset(pre, -1, sizeof(pre));
        memset(sta, 0, sizeof(sta));
        init();
        int num = n, hefa = n * 0.2;
        for(int i = n + 1; i <= n + m; i++) {
            if(node[i].kind == 2) {
                int id = node[i].tobit;
                int name = node[i].id;
                pre[name] = id;
                bit.add(id, 1);
                num++;
                if(num % 5 == 0) {
                    hefa++;
                    int ran = bit.sum(id);
                    if(ran <= hefa) {
                        if(sta[name] == 0) {
                            cout << emp[name] << "is working hard now.\n";
                        }
                        sta[name] = 1;
                    }
                    else {
                        int nomoreedit = work(hefa);
                        if(sta[nomoreedit] == 0)
                            cout << emp[nomoreedit] << "is not working now.\n";
                        sta[nomoreedit] = 1;
                    }
                }
                else {
                    int ran = bit.sum(id);
                    if(ran > hefa) {
                        sta[name] = 0; cout << emp[name] << "is not working now.\n";
                    }
                    else {
                        sta[name] = 1;
                        cout << emp[name] << "is working hard now.\n";
                        int nomorework = work(hefa + 1);
                        sta[nomorework] = 0;
                        cout << emp[nomorework] << "is not working now.\n";
                    }
                }
            }
            else if(node[i].kind == 3) {
                int name = node[i].id;
                bit.add(pre[name], -1);
                pre[name] = -1;
                num--;
                if(num % 5 == 4) {
                    hefa--;
                    if(sta[name] == 1) {
                        sta[name] = 0;
                        cout << emp[name] << "is not working now.\n";
                    }
                    else {
                        int nomorework = work(hefa + 1);
                        sta[nomorework] = 0;
                        cout << emp[nomorework] << "is not working now.\n";
                    }
                }
                else {
                    if(sta[name] == 1) {
                        sta[name] = 0;
                        cout << emp[name] << "is not working now.\n";
                        int nomoreedit = work(hefa);
                        sta[nomoreedit] = 1;
                        cout << emp[nomoreedit] << "is not working now.\n";
                    }
                    else {
                        sta[name] = 0;
                    }
                }
            }
        }
    }
    return 0;
}
