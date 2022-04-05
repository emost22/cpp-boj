#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 201
using namespace std;
typedef pair<int, int> pi;

string str;
vector<pi> list;
set<string> ans;
bool visit[MAX];
int N, M;

void dfs(int idx, int cnt) {
	if (idx == M) {
		if (cnt == M) return;
		string tmp = "";
		for (int i = 0; i < N; i++) {
			if (str[i] == '(' || str[i] == ')') {
				if (!visit[i]) continue;
			}

			tmp += str[i];
		}

		ans.insert(tmp);
		return;
	}

	int l = list[idx].first;
	int r = list[idx].second;

	visit[l] = true;
	visit[r] = true;
	dfs(idx + 1, cnt + 1);
	visit[l] = false;
	visit[r] = false;
	dfs(idx + 1, cnt);
}

void func() {
	dfs(0, 0);
	set<string>::iterator iter = ans.begin();
	for (; iter != ans.end(); iter++) {
		cout << (*iter) << '\n';
	}
}

void init() {
	stack<int> s;
	for (int i = 0; i < N; i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else if (str[i] == ')') {
			int x = s.top();
			s.pop();
			list.push_back({ x, i });
		}
	}
	M = list.size();
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	func();

	return 0;
}