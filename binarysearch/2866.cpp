#include <iostream>
#include <string>
#include <unordered_set>
#define MAX 1001
using namespace std;

string strList[MAX];
int N, M;

bool solve(int idx) {
	unordered_set<string> s;
	for (int j = 0; j < M; j++) {
		string str = "";
		for (int i = idx; i < N; i++) {
			str += strList[i][j];
		}

		if (s.find(str) != s.end()) return false;
		s.insert(str);
	}
	s.clear();

	return true;
}

void func() {
	int ans = 0;
	int l = 0;
	int r = N - 1;
	while (l <= r) {
		int m = (l + r) / 2;

		if (solve(m)) {
			l = m + 1;
			ans = m;
		}
		else {
			r = m - 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> strList[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}