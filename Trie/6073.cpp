#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 10001
using namespace std;

int list[MAX];
int N, M, K, ans;

typedef struct Trie {
	int isEnd;
	int cnt;
	Trie* next[2];

	Trie() {
		isEnd = 0;
		cnt = 0;
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		isEnd = 0;
		cnt = 0;
		for (int i = 0; i < 2; i++) {
			delete next[i];
		}
	}

	void insert(int idx) {
		if (idx == K) {
			isEnd++;
			return;
		}

		if (!next[list[idx]]) next[list[idx]] = new Trie();
		next[list[idx]]->cnt++;
		next[list[idx]]->insert(idx + 1);
	}

	void find(int idx) {
		if (idx == K) {
			ans += cnt;
			return;
		}

		if (isEnd) {
			ans += isEnd;
		}

		if (!next[list[idx]]) return;
		next[list[idx]]->find(idx + 1);
	}
}Trie;

Trie* t;

void func() {
	while (M--) {
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> list[i];
		}
		t->find(0);
		cout << ans << '\n';
		ans = 0;
	}
}

void init() {
	t = new Trie();
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> list[j];
		}
		t->insert(0);
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