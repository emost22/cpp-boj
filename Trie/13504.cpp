#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 100001
#define MAX_M 31
using namespace std;

int list[MAX_N];
int N;

typedef struct Trie {
	bool isEnd;
	Trie *next[2];

	Trie() {
		isEnd = false;
		memset(next, false, sizeof(next));
	}

	~Trie() {
		isEnd = false;
		for (int i = 0; i < 2; i++) {
			delete next[i];
		}
	}

	void insert(int x, int bit) {
		if (bit < 0) {
			isEnd = true;
			return;
		}

		int pos = x & (1 << bit);
		if (pos) pos = 1;
		
		if (!next[pos]) next[pos] = new Trie();
		next[pos]->insert(x & ~(1 << bit), bit - 1);
	}

	int find(int x, int bit) {
		if (isEnd) return 0;

		int pos = x & (1 << bit);
		pos = pos ? 0 : 1;

		int ret = 0;
		if (!next[pos]) pos = 1 - pos;
		else ret = 1 << bit;

		return ret + next[pos]->find(x & ~(1 << bit), bit - 1);
	}
}Trie;

Trie *t;

void func() {
	int ans = 0;
	int now = 0;
	t->insert(now, MAX_M);
	for (int i = 0; i < N; i++) {
		now ^= list[i];
		t->insert(now, MAX_M);
		ans = max(ans, t->find(now, MAX_M));
	}

	cout << ans << '\n';
}

void init() {
	delete t;
	t = new Trie();
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		init();
		input();
		func();
	}

	return 0;
}