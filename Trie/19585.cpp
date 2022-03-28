#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define MAX 2001
using namespace std;

string str;
bool colorChk[MAX], nameChk[MAX];
int N, M, K, len;

typedef struct Trie {
	int isEnd;
	// map<char, Trie*> next;
	vector<pair<char, Trie*>> next;

	Trie() {
		isEnd = false;
	}

	~Trie() {
		isEnd = false;
		next.clear();
	}

	void insert(int idx) {
		if (str.size() == idx) {
			isEnd = true;
			return;
		}

		int pos = -1;
		for (int i = 0; i < next.size(); i++) {
			if (next[i].first == str[idx]) {
				pos = i;
				break;
			}
		}

		if (pos == -1) {
			next.push_back({ str[idx], new Trie() });
			pos = next.size() - 1;
		}
		next[pos].second->insert(idx + 1);
	}

	void cfind(int idx) {
		if (isEnd) {
			colorChk[idx] = true;
		}

		if (idx == len) return;

		int pos = -1;
		for (int i = 0; i < next.size(); i++) {
			if (next[i].first == str[idx]) {
				pos = i;
				break;
			}
		}

		if (pos == -1) return;
		next[pos].second->cfind(idx + 1);
	}

	void nfind(int idx) {
		if (isEnd) {
			nameChk[len - 1 - idx] = true;
		}

		if (idx == -1) return;

		int pos = -1;
		for (int i = 0; i < next.size(); i++) {
			if (next[i].first == str[idx]) {
				pos = i;
				break;
			}
		}

		if (pos == -1) return;
		next[pos].second->nfind(idx - 1);
	}
}Trie;

Trie *color, *nick;

void func() {
	cin >> K;
	while (K--) {
		cin >> str;
		len = str.size();

		memset(colorChk, false, sizeof(colorChk));
		memset(nameChk, false, sizeof(nameChk));

		color->cfind(0);
		nick->nfind(str.size() - 1);

		bool flag = false;
		for (int i = 1; i <= len; i++) {
			if (colorChk[i] && nameChk[len - i]) {
				flag = true;
				break;
			}
		}

		if (flag) {
			cout << "Yes\n";
		}
		else cout << "No\n";
	}
}

void init() {
	color = new Trie();
	nick = new Trie();
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		color->insert(0);
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		reverse(str.begin(), str.end());
		nick->insert(0);
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