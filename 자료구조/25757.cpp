#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

char ch;
int N;

void play(int maxCnt) {
	int ret = 0;
	int cnt = 0;

	unordered_set<string> s;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (s.find(str) != s.end()) continue;

		cnt++;
		s.insert(str);

		if (cnt == maxCnt) {
			ret++;
			cnt = 0;
		}
	}

	cout << ret << '\n';
}

void func() {
	if (ch == 'Y') {
		play(1);
	}
	else if (ch == 'F') {
		play(2);
	}
	else {
		play(3);
	}
}

void input() {
	cin >> N >> ch;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}