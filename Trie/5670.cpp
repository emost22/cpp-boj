#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define MAX 100001
#define LEN 81
using namespace std;

char list[MAX][LEN];
int N, M, ans;

int charToInt(char x) {
	return x - 'a';
}

typedef struct Trie {
	bool isRoot;
	bool isEnd;
	int cnt;
	Trie* alpha[26];

	Trie() {
		memset(alpha, 0, sizeof(alpha));
		isEnd = false;
		isRoot = false;
		cnt = 0;
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (alpha[i]) delete alpha[i];
		}
	}

	void insert(char *x) {
		if (*x == '\0') {
			isEnd = true;
			return;
		}

		int idx = charToInt(*x);
		if (!alpha[idx]) {
			alpha[idx] = new Trie();
			cnt++;
		}
		alpha[idx]->insert(x + 1);
	}

	void find(char *x, int k) {
		if (*x == '\0') {
			ans += k;
			return;
		}

		int idx = charToInt(*x);
		if (isRoot) alpha[idx]->find(x + 1, k);
		else {
			if (cnt > 1 || isEnd) alpha[idx]->find(x + 1, k + 1);
			else alpha[idx]->find(x + 1, k);
		}
	}
}Trie;

Trie *t;

void func() {
	cout << fixed;
	cout.precision(2);

	for (int i = 0; i < N; i++) {
		t->find(list[i], 1);
	}
	
	cout << (double)ans / N << '\n';
	delete t;
}

void init() {
	t = new Trie();
	t->isRoot = true;
	ans = 0;
}

void input() {
	init();
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		t->insert(list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		input();
		func();
	}

	return 0;
}