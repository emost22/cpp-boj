#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

string str;
int N, K;

int bfs() {
	unordered_set<string> s;
	queue<string> q;
	q.push(str);
	s.insert(str);
	sort(str.begin(), str.end());
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			string cur = q.front();
			q.pop();

			if (cur == str) return t;

			for (int i = 0; i < N - K + 1; i++) {
				string tmp = cur;
				reverse(tmp.begin() + i, tmp.begin() + i + K);

				if (s.find(tmp) != s.end()) continue;
				s.insert(tmp);
				q.push(tmp);
			}
		}
	}

	return -1;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	char x;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> x;
		str += x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}