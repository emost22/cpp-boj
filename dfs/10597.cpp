#include <iostream>
#include <string>
#include <vector>
#define MAX 51
using namespace std;

vector<int> v;
string str;
bool visit[MAX];
int len, N;

void dfs(int idx) {
	if (idx == len) {
		for (auto x : v) {
			cout << x << ' ';
		}
		cout << '\n';
		exit(0);
	}
	if (str[idx] == '0') return;

	int nx = str[idx] - '0';
	if (nx && !visit[nx]) {
		v.push_back(nx);
		visit[nx] = true;
		dfs(idx + 1);
		visit[nx] = false;
		v.pop_back();
	}

	if (idx + 1 < len) {
		nx = nx * 10 + str[idx + 1] - '0';
		if (nx <= N && !visit[nx]) {
			v.push_back(nx);
			visit[nx] = true;
			dfs(idx + 2);
			visit[nx] = false;
			v.pop_back();
		}
	}
}

void func() {
	len = str.size();
	N = ((len - 9) >> 1) + 9;
	dfs(0);
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}