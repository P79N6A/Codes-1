#include<algorithm>
#include<bitset>
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
#define pr(x) cout << #x << " = " << (x) << " ; ";
#define prln(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;
const int LEN = 7;
int x[] = {1, 3, 6, 8, 12, 7, 3};
int y[] = {7, 1, 5, 1, 9, 8, 12};

struct CAET {
	int x;
	double nk;
	int ymx;
	bool operator < (const CAET& t)const {
		if (x == t.x) return nk < t.nk;
		return x < t.x;
	}
};

vector<CAET> aet[20];

// 有效边表填充算法
void AET() {
	// 建立NET
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < LEN; ++j) {
			if (y[j] == i) {
				int pre = (j - 1 + LEN) % LEN;
				int nxt = (j + 1) % LEN;
				if (y[pre] > y[j]) {
					aet[i].push_back(CAET{ x[j], (double)(x[pre] - x[j]) / (y[pre] - y[j]), y[pre]});
				}
				if (y[nxt] > y[j]) {
					aet[i].push_back(CAET{ x[j], (double)(x[nxt] - x[j]) / (y[nxt] - y[j]), y[nxt] });
				}
			}
		}
		if (aet[i].size()) {
            prln(i)
            for (int j = 0; j < aet[i].size(); ++j) pr(aet[i][j].nk);
            prln("");
		}
	}
	// 一边建立AET，一边绘制
	for (int i = 0; i < 20; ++i) {
		if (i) {
			for (int j = 0; j < aet[i - 1].size(); ++j) {
				CAET &cur = aet[i - 1][j];
				if (cur.ymx > i) {
					aet[i].push_back(CAET{ cur.x + cur.nk, cur.nk, cur.ymx});
				}
			}
		}
		//pr(i)
		//prln(aet[i].size());
		sort(aet[i].begin(), aet[i].end());
		// 绘制
		for (int j = 0; j < aet[i].size(); j += 2) {
            pr(aet[i][j].x) prln(aet[i][j + 1].x);
			for (int k = aet[i][j].x; k < aet[i][j + 1].x; ++k) {
				//drawRt(pDC, k, i);
			}
		}
	}
}

int main()
{
    AET();
    return 0;
}
