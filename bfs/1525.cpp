#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <vector>
#define answer "123456780"
using namespace std;

vector<int> graph[9];
queue<pair<int, pair<string, int> > > q;
set<string> visit;
string N;

void init() {
	graph[0].push_back(1);
	graph[0].push_back(3);

	graph[1].push_back(0);
	graph[1].push_back(2);
	graph[1].push_back(4);

	graph[2].push_back(1);
	graph[2].push_back(5);

	graph[3].push_back(0);
	graph[3].push_back(4);
	graph[3].push_back(6);

	graph[4].push_back(1);
	graph[4].push_back(3);
	graph[4].push_back(5);
	graph[4].push_back(7);

	graph[5].push_back(2);
	graph[5].push_back(4);
	graph[5].push_back(8);

	graph[6].push_back(3);
	graph[6].push_back(7);

	graph[7].push_back(4);
	graph[7].push_back(6);
	graph[7].push_back(8);

	graph[8].push_back(5);
	graph[8].push_back(7);
}

void bfs() {
	while (!q.empty()) {
		string now = q.front().second.first;
		int idx = q.front().second.second;
		int cnt = q.front().first;
		q.pop();

		if (now == answer) {
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < graph[idx].size(); i++) {
			int next = graph[idx][i];

			string str = now;
			swap(str[idx], str[next]);
			if (visit.find(str) != visit.end()) continue;

			q.push({ cnt + 1, {str, next} });
			visit.insert(str);
		}
	}

	cout << "-1\n";
	return;
}

void input() {
	char ch;
	int zero = 0;
	for (int i = 0; i < 9; i++) {
		cin >> ch;
		N += ch;
		if (ch == '0') zero = i;
	}

	visit.insert(N);
	q.push({ 0, {N, zero} });
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	bfs();

	return 0;
}