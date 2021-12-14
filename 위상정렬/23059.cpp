#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 400000
using namespace std;
typedef pair<int, int> pi;

unordered_map<int, string> intToString;
unordered_map<string, int> stringToInt;
vector<int> graph[MAX], ans[MAX];
int conn[MAX];
int N, idx;

bool cmp(int a, int b) {
	return intToString[a] < intToString[b];
}

void print() {
	for (int i = 0; ; i++) {
		if (!ans[i].size()) return;

		sort(ans[i].begin(), ans[i].end(), cmp);
		for (int j = 0; j < ans[i].size(); j++) {
			cout << intToString[ans[i][j]] << '\n';
		}
	}
}

void func() {
	queue<pi> q;
	for (int i = 0; i < idx; i++) {
		if (!conn[i]) {
			q.push({ i,0 });
			ans[0].push_back(i);
		}
	}

	for (int t = 1; t < idx; t++) {
		if (q.empty()) {
			cout << "-1\n";
			return;
		}

		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];

			conn[next]--;

			if (!conn[next]) {
				q.push({ next, cnt + 1 });
				ans[cnt + 1].push_back(next);
			}
		}
	}

	print();
}

void input() {
	string str1, str2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str1 >> str2;

		if (stringToInt.find(str1) == stringToInt.end()) {
			stringToInt.insert({ str1, idx });
			intToString.insert({ idx++, str1 });
		}
		if (stringToInt.find(str2) == stringToInt.end()) {
			stringToInt.insert({ str2, idx });
			intToString.insert({ idx++, str2 });
		}

		int a = stringToInt[str1];
		int b = stringToInt[str2];
		graph[a].push_back(b);
		conn[b]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}