#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str;
int N, M;

typedef struct Trie {
	bool isEnd;
	Trie* next[26];

	Trie() {
		isEnd = false;
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		isEnd = false;
		for (int i = 0; i < 26; i++) {
			delete next[i];
		}
	}

	void insert(int idx, int len) {
		if (idx == len) {
			isEnd = true;
			return;
		}

		int pos = str[idx] - 'a';
		if (!next[pos]) next[pos] = new Trie();
		next[pos]->insert(idx + 1, len);
	}

	int find(int idx, int len) {
		if (idx == len) return 1;

		int pos = str[idx] - 'a';
		if (!next[pos]) return 0;
		return next[pos]->find(idx + 1, len);
	}
}Trie;

Trie* t;

void func() {
	int ans = 0;
	while (M--) {
		cin >> str;
		ans += t->find(0, str.size());
	}

	cout << ans << '\n';
}

void init() {
	t = new Trie();
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		t->insert(0, str.size());
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