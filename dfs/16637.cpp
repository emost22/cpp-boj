#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define INF 2147483647
using namespace std;

string str;
bool chk[20];
int N;
int ans = -INF;

int solve() {
	vector<int> v;
	vector<char> op;

	int i = 0;
	while (i < N) {
		if (chk[i]) {
			if (str[i + 1] == '+') {
				v.push_back(str[i] - '0' + str[i + 2] - '0');
			}
			else if (str[i + 1] == '-') {
				v.push_back(str[i] - '0' - str[i + 2] + '0');
			}
			else {
				v.push_back((str[i] - '0') * (str[i + 2] - '0'));
			}
			if (str[i + 3]) op.push_back(str[i + 3]);
			i += 4;
		}
		else {
			v.push_back(str[i] - '0');
			if (str[i + 1]) op.push_back(str[i + 1]);
			i += 2;
		}
	}

	int ret = v[0];
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '+') {
			ret += v[i + 1];
		}
		else if (op[i] == '-') {
			ret -= v[i + 1];
		}
		else {
			ret *= v[i + 1];
		}
	}

	return ret;
}

void dfs(int idx) {
	ans = max(ans, solve());

	for (int i = idx; i < N - 1; i += 2) {
		chk[i] = true;
		dfs(i + 4);
		chk[i] = false;
	}
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	dfs(0);
	cout << ans << '\n';

	return 0;
}