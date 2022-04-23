#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;

unordered_set<string> s;
int N;

int charToInt(char x) {
	return x - 'a';
}

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

	void insert(string str, int idx, int len) {
		if (idx == len) {
			isEnd = true;
			return;
		}

		int pos = charToInt(str[idx]);
		if (!next[pos]) next[pos] = new Trie();

		next[pos]->insert(str, idx + 1, len);
	}

	int find(string str, int idx, int len) {
		if (idx == len) {
			for (int i = 0; i < 26; i++) {
				if (next[i]) {
					return 0;
				}
			}

			return 1;
		}

		int pos = charToInt(str[idx]);
		return next[pos]->find(str, idx + 1, len);
	}
}Trie;

Trie* t;

void init() {
	t = new Trie();
}

void func() {
	int ans = 0;
	unordered_set<string>::iterator iter = s.begin();
	for (; iter != s.end(); iter++) {
		t->insert((*iter), 0, (*iter).size());
	}

	for (iter = s.begin(); iter != s.end(); iter++) {
		ans += t->find((*iter), 0, (*iter).size());
	}

	cout << ans << '\n';
}

void input() {
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
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