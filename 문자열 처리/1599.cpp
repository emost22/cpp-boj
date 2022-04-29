#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#define MAX 51
using namespace std;

map<string, string> a, b;
string list[MAX], tmp[MAX];
int N;

void init() {
	a.insert({ "a", "a" });
	a.insert({ "b", "b" });
	a.insert({ "k", "c" });
	a.insert({ "d", "d" });
	a.insert({ "e", "e" });
	a.insert({ "g", "f" });
	a.insert({ "h", "g" });
	a.insert({ "i", "h" });
	a.insert({ "l", "i" });
	a.insert({ "m", "j" });
	a.insert({ "n", "k" });
	a.insert({ "ng", "l" });
	a.insert({ "o", "m" });
	a.insert({ "p", "n" });
	a.insert({ "r", "o" });
	a.insert({ "s", "p" });
	a.insert({ "t", "q" });
	a.insert({ "u", "r" });
	a.insert({ "w", "s" });
	a.insert({ "y", "t" });

	b.insert({ "a", "a" });
	b.insert({ "b", "b" });
	b.insert({ "c", "k" });
	b.insert({ "d", "d" });
	b.insert({ "e", "e" });
	b.insert({ "f", "g" });
	b.insert({ "g", "h" });
	b.insert({ "h", "i" });
	b.insert({ "i", "l" });
	b.insert({ "j", "m" });
	b.insert({ "k", "n" });
	b.insert({ "l", "ng" });
	b.insert({ "m", "o" });
	b.insert({ "n", "p" });
	b.insert({ "o", "r" });
	b.insert({ "p", "s" });
	b.insert({ "q", "t" });
	b.insert({ "r", "u" });
	b.insert({ "s", "w" });
	b.insert({ "t", "y" });
}

void func() {
	for (int i = 0; i < N; i++) {
		int M = list[i].size();
		for (int j = 0; j < M; j++) {
			if (list[i][j] == 'n') {
				if (j < M - 1) {
					if (list[i][j + 1] == 'g') {
						tmp[i] += a[list[i].substr(j, 2)];
						j++;
					}
					else tmp[i] += a[list[i].substr(j, 1)];
				}
				else tmp[i] += a[list[i].substr(j, 1)];
			}
			else tmp[i] += a[list[i].substr(j, 1)];
		}
	}
	sort(tmp, tmp + N);

	for (int i = 0; i < N; i++) {
		int M = tmp[i].size();
		for (int j = 0; j < M; j++) {
			cout << b[tmp[i].substr(j, 1)];
		}
		cout << '\n';
	}
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

	init();
	input();
	func();

	return 0;
}