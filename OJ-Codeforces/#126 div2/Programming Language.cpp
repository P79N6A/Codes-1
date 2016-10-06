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
const int MAXN = 1e3 + 5;

struct Trie {
    int nxt[MAXN * 10][36];
    vector<vector<string>> ty[MAXN * 10];
    int root, len;
    int newnode() {
        for (int i = 0; i < 36; ++i) nxt[len][i] = -1;
        ty[len++].clear();
        return len - 1;
    }
    void init() {
        len = 0;
        root = newnode();
    }
    void add(string s, vector<string> &t) {
        int now = root;
        for (int i = 0; i < s.length(); ++i) {
            int v = s[i] - 'a';
            if (isdigit(s[i])) {
                v = 26 + s[i] - '0';
            }
            if (nxt[now][v] == -1) {
                nxt[now][v] = newnode();
            }
            now = nxt[now][v];
        }
        ty[now].push_back(t);
    }
    int query(string s, vector<string> &t) {
        int now = root;
        for (int i = 0; i < s.length(); ++i) {
            int v = s[i] - 'a';
            if (isdigit(s[i])) {
                v = 26 + s[i] - '0';
            }
            if (nxt[now][v] == -1) {
                return 0;
            }
            now = nxt[now][v];
        }
        int ret = 0;
        for (int i = 0; i < ty[now].size(); ++i) {
            vector<string> &temp = ty[now][i];
            if (temp.size() != t.size()) continue;
            bool flag = 1;
            for (int j = 0; j < temp.size(); ++j) {
                if (temp[j] == "T") continue;
                if (temp[j] != t[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ++ret;
        }
        return ret;
    }
}trie;
map<string, string> type;

int main()
{
    #ifdef GooZy
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n;
    string s, s2;
    cin.ignore();
    trie.init();
    while (n --) {
        getline(cin, s);
        for (int i = 0; i < s.length(); ++i) {
            if (!isalpha(s[i]) && !isdigit(s[i])) {
                s[i] = ' ';
            }
        }
        int tol = 0;
        string name;
        stringstream ss(s);
        vector<string> temp;
        while (ss >> s2) {
            ++tol;
            if (tol == 2) name = s2;
            else if (tol > 2) {
                temp.push_back(s2);
            }
        }
        trie.add(name, temp);
    }
    cin >> m;
    while (m --) {
        cin >> s >> s2;
        type[s2] = s;
    }
    cin >> k;
    cin.ignore();
    while (k --) {
        getline(cin, s);
        for (int i = 0; i < s.length(); ++i) {
            if (!isalpha(s[i]) && !isdigit(s[i])) {
                s[i] = ' ';
            }
        }
        int tol = 0;
        string name;
        stringstream ss(s);
        vector<string> temp;
        while (ss >> s2) {
            ++tol;
            if (tol == 1) name = s2;
            else if (tol > 1) {
                temp.push_back(type[s2]);
            }
        }
        cout << trie.query(name, temp) << '\n';
    }
    return 0;
}
