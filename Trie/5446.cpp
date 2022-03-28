#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int N, M, ans;

typedef struct Trie {
	bool isEnd;
	bool flag;
	map<char, Trie*> m;

	Trie() {
		isEnd = false;
		flag = false;
	}

	~Trie() {
		isEnd = false;
		flag = false;
		map<char, Trie*>::iterator iter = m.begin();
		for (; iter != m.end(); iter++) {
			delete (*iter).second;
		}
	}

	void insert(string str, int idx) {
		if (idx == str.size()) {
			isEnd = true;
			return;
		}

		if (m.find(str[idx]) == m.end()) m.insert({ str[idx], new Trie() });
		m[str[idx]]->insert(str, idx + 1);
	}

	void noErase(string str, int idx) {
		flag = true;
		if (idx == str.size()) {
			return;
		}

		if (m.find(str[idx]) == m.end()) return;
		m[str[idx]]->noErase(str, idx + 1);
	}

	void find() {
		if (!flag) {
			ans++;
			return;
		}
		if (isEnd) ans++;

		map<char, Trie*>::iterator iter = m.begin();
		for (; iter != m.end(); iter++) {
			(*iter).second->find();
		}
	}
}Trie;

Trie *t;

void func() {
	t->find();
	cout << ans << '\n';
}

void init() {
	delete t;
	t = new Trie();
	ans = 0;
}

void input() {
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		t->insert(str, 0);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> str;
		t->noErase(str, 0);
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