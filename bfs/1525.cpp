#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

typedef struct list {
	string now;
	int idx;
	int cnt;
}list;

queue<list> q;
set<string> s;
vector<int> v[9];
string ans = "123456780", str = "";

void init() {
	v[0].push_back(1);
	v[0].push_back(3);

	v[1].push_back(0);
	v[1].push_back(2);
	v[1].push_back(4);

	v[2].push_back(1);
	v[2].push_back(5);

	v[3].push_back(0);
	v[3].push_back(4);
	v[3].push_back(6);

	v[4].push_back(1);
	v[4].push_back(3);
	v[4].push_back(5);
	v[4].push_back(7);

	v[5].push_back(2);
	v[5].push_back(4);
	v[5].push_back(8);

	v[6].push_back(3);
	v[6].push_back(7);

	v[7].push_back(4);
	v[7].push_back(6);
	v[7].push_back(8);

	v[8].push_back(5);
	v[8].push_back(7);
}

void bfs() {
	while (!q.empty()) {
		string now = q.front().now;
		int idx = q.front().idx;
		int cnt = q.front().cnt;
		q.pop();

		if (!now.compare(ans)) {
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < v[idx].size(); i++) {
			int next = v[idx][i];
			string tmp = now;
			swap(tmp[idx], tmp[next]);

			if (s.find(tmp) != s.end()) continue;

			q.push({ tmp, next, cnt + 1 });
			s.insert(tmp);
		}
	}

	cout << "-1\n";
}

void input() {
	int k = 0;
	string tmp = "";
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		str += tmp;

		if (tmp[0] == '0') {
			k = i;
		}
	}

	q.push({ str, k, 0 });
	s.insert(str);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	bfs();

	return 0;
}