#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define MAX 1001
using namespace std;

map<string, int> m;
string ans[MAX];
int idx[MAX];
int N;

void func() {
	string str;
	for (int i = 0; i < N; i++) {
		cin >> ans[idx[i]];
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void input() {
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		m.insert({ str, i });
	}

	for (int i = 0; i < N; i++) {
		cin >> str;
		idx[i] = m[str];
	}
}

void init() {
	m.clear();
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