#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#define MAX 501
using namespace std;

string list[MAX][MAX];
int N, M;

typedef struct Trie {
	map<string, Trie*> m;

	~Trie() {
		map<string, Trie*>::iterator iter = m.begin();
		for (; iter != m.end(); iter++) {
			delete (*iter).second;
		}
	}

	void insert(int i, int idx) {
		if (idx == M) return;

		if (m.find(list[i][idx]) == m.end()) m.insert({ list[i][idx], new Trie() });
		m[list[i][idx]]->insert(i, idx + 1);
	}

	void find(int depth) {
		map<string, Trie*>::iterator iter = m.begin();
		for (; iter != m.end(); iter++) {
			for (int i = 0; i < depth; i++) {
				cout << ' ';
			}
			cout << (*iter).first << '\n';
			(*iter).second->find(depth + 1);
		}
	}
}Trie;

Trie* t;

void func() {
	t->find(0);
}

void init() {
	t = new Trie();
}

void input() {
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int idx = 0;
		int len = str.size();
		for (int j = 0; j < len; j++) {
			if (str[j] == '\\') {
				idx++;
				continue;
			}
			list[i][idx] += str[j];
		}
		M = idx + 1;
		t->insert(i, 0);
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