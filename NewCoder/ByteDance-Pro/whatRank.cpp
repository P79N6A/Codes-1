#include<iostream>
#include<vector>

using namespace std;

// rnk[i]：学校i的排名是rnk[i]
int rnk[5];

// Guess存放的是单个猜测，name是学校名对应的数字，比如A是0
// rnk是猜测的这个学校的排名，从0开始算排名
struct Guess {
	int name;
	int rnk;
};

// 存放每个人的猜测结果
vector<Guess> guess[5];

bool solve(char s[]) {

	// 根据排名结果给rnk数组赋值
	for (int i = 0; i < 5; ++i) {
		rnk[s[i] - 'A'] = i;
	}

	// 验证别人说的话是否是正确的，从第i名开始验证
	for (int i = 0; i < 5; ++i) {
		// 排名第i的学校
		int cur = s[i] - 'A';
		for (int j = 0; j < guess[cur].size(); ++j) {
			int name = guess[cur][j].name;
			int rk = guess[cur][j].rnk;
			// 如果是前两名，那么他说的话一定正确
			if (i < 2) {
				// 矛盾，返回false
				if (rnk[name] != rk)
					return false;
			}
			// 如果是后三名，那么他说的话一定错误
			else {
				// 矛盾，返回false
				if (rnk[name] == rk) 
					return false;
			}
		}
	}
	// E不能为第二名或者第三名
	if (rnk[4] == 1 || rnk[4] == 2) return false;
	return true;
}

int main() {
	// 初始化猜测结果
	// A校的猜测：
	guess[0].push_back(Guess{'E' - 'A', 0});
	// B校的猜测：
	guess[1].push_back(Guess{'B' - 'A', 1});
	// C校的猜测：
	guess[2].push_back(Guess{'A' - 'A', 4});
	// D校的猜测：
	guess[3].push_back(Guess{'C' - 'A', 1});
	guess[3].push_back(Guess{'C' - 'A', 2});
	guess[3].push_back(Guess{'C' - 'A', 3});
	guess[3].push_back(Guess{'C' - 'A', 4});
	// E校的猜测：
	guess[4].push_back(Guess{'D' - 'A', 0});


	// 学校排名的可能排列
	char rankString[6] = {'A', 'B', 'C', 'D', 'E'};

	bool hasAnswer = false;

	// 枚举整个排列
	do {
		if (solve(rankString)) {
			hasAnswer = true;
			break;
		}
	} while (next_permutation(rankString, rankString + 5));

	if (!hasAnswer) {
		cout << "没有正确答案\n";
		return 0;
	}

	cout << "排名结果如下：\n";
	for (int i = 0; i < 5; ++i) {
		cout << (char)('A' + i) << ": " << rnk[i] + 1 << '\n';
	}
}