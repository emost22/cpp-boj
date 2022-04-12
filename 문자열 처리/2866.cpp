#include <iostream>
#include <string>
#include <unordered_set>
#define MAX 1001
using namespace std;

string strList[MAX], ans[MAX];
int N, M;

void func() {
	for (int i = N - 1; i >= 0; i--) {
		unordered_set<string> s;
		bool flag = true;
		for (int j = 0; j < M; j++) {
			ans[j] += strList[i][j];
			if (s.find(ans[j]) != s.end()) flag = false;
			else s.insert(ans[j]);
		}

		if (flag) {
			cout << i << '\n';
			return;
		}

		s.clear();
	}
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