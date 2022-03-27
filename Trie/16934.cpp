#include <iostream>
#include <string>
#include <cstring>
#define MAX 100001
using namespace std;

string ans[MAX], list[MAX];
int N;

int charToInt(char c) {
	return c - 'a';
}

typedef struct Trie {
	int cnt;
	Trie* next[26];

	Trie() {
		cnt = 0;
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			delete next[i];
		}
	}

	void insert(int ansIdx, int idx, bool flag) {
		if (idx == list[ansIdx].size()) {
			cnt++;
			if (cnt > 1) ans[ansIdx] += to_string(cnt);
			return;
		}

		int pos = list[ansIdx][idx] - 'a';
		if (!flag) ans[ansIdx] += list[ansIdx][idx];
		if (!next[pos]) {
			next[pos] = new Trie();
			next[pos]->insert(ansIdx, idx + 1, true);
		}
		else {
			next[pos]->insert(ansIdx, idx + 1, flag);
		}
	}
}Trie;

Trie* t;

void func() {
	for (int i = 0; i < N; i++) {
		cout << ans[i] << '\n';
	}
}

void init() {
	t = new Trie();
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		t->insert(i, 0, false);
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