#include <iostream>
#include <string>
#define MAX 26
using namespace std;

string str;
int alpha[MAX];
int N, ret;

void dfs(int idx, string now) {
	if (idx == N) {
		ret++;
		return;
	}

	for (int i = 0; i < MAX; i++) {
		if (!alpha[i]) continue;
		if (idx && now[idx - 1] == (char)(i + 'a')) continue;

		alpha[i]--;
		dfs(idx + 1, now + (char)(i + 'a'));
		alpha[i]++;
	}
}

void func() {
	dfs(0, "");
	cout << ret << '\n';
}

void input() {
	cin >> str;
	N = str.size();
	for (int i = 0; i < N; i++) {
		alpha[str[i] - 'a']++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}