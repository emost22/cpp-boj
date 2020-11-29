#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
map<string, int> m;
string str[10001];

void func() {
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (m.find(str[i]) != m.end()) cnt++;
	}

	cout << cnt << '\n';
}

void input() {
	string s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		m.insert({ s, 1 });
	}

	for (int i = 0; i < M; i++) {
		cin >> str[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}