#include <iostream>
#include <map>
#include <string>
#define MAX 16
using namespace std;

string list[MAX];
int N, M;

typedef struct Trie {
	map<string, Trie*> m;

	~Trie() {
		map<string, Trie*>::iterator iter = m.begin();
		for (; iter != m.end(); iter++) {
			delete (*iter).second;
		}
	}

	void insert(int idx) {
		if (idx == M) return;

		if (m.find(list[idx]) == m.end()) {
			m.insert({ list[idx], new Trie() });
			m[list[idx]]->insert(idx + 1);
		}
		else {
			m[list[idx]]->insert(idx + 1);
		}
	}

	void find(int depth) {
		map<string, Trie*>::iterator iter = m.begin();
		for (; iter != m.end(); iter++) {
			for (int i = 0; i < depth; i++) {
				cout << "--";
			}
			cout << (*iter).first << '\n';

			(*iter).second->find(depth + 1);
		}
	}
}Trie;

Trie *t;

void func() {
	t->find(0);
}

void init() {
	t = new Trie();
}

void input() {
	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> list[j];
		}
		t->insert(0);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}