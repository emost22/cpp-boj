#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
typedef pair<int, int> pi;

priority_queue<pi, vector<pi>, greater<>> q;
string ans[MAX];
int list[MAX];
int N;

typedef struct Trie {
	bool isEnd;
	Trie *next[2];

	Trie() {
		isEnd = false;
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 2; i++) {
			delete next[i];
		}
	}

	bool insert(int idx, int depth, string str) {
		if (isEnd) return false;

		if (!depth) {
			ans[idx] = str;
			isEnd = true;
			return true;
		}

		if (!next[0]) next[0] = new Trie();
		if (next[0]->insert(idx, depth - 1, str + '0')) return true;

		if (!next[1]) next[1] = new Trie();
		return next[1]->insert(idx, depth - 1, str + '1');
	}
}Trie;

Trie *t;

void init() {
	t = new Trie();
}

void func() {
	bool flag = true;
	while (!q.empty()) {
		int depth = q.top().first;
		int idx = q.top().second;
		q.pop();

		if (!t->insert(idx, depth, "")) {
			flag = false;
			break;
		}
	}

	if (!flag) {
		cout << "-1\n";
		return;
	}

	cout << "1\n";
	for (int i = 0; i < N; i++) {
		cout << ans[i] << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		q.push({ list[i], i });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}