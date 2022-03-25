#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define MAX 10001
using namespace std;

char list[MAX][11];
int N;

int charToInt(char x) {
	return x - '0';
}

typedef struct Trie {
	bool isEnd;
	Trie *next[10];
	Trie() : isEnd(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (next[i]) delete next[i];
		}
	}

	void insert(char *key) {
		if (*key == '\0') {
			isEnd = true;
		}
		else {
			int idx = charToInt(*key);
			if (!next[idx]) next[idx] = new Trie();
			next[idx]->insert(key + 1);
		}
	}

	bool find(char *key) {
		if (*key == '\0') return true;
		if (isEnd) return false;

		int idx = charToInt(*key);
		return next[idx]->find(key + 1);
	}
}Trie;

Trie *t;

void func() {
	for (int i = 0; i < N; i++) {
		if (!(t->find(list[i]))) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

void input() {
	t = new Trie();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		t->insert(list[i]);
	}
}

void init() {
	delete t;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}