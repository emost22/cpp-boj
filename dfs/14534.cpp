#include <iostream>
#include <string>
#define MAX 5
using namespace std;

bool visit[MAX];
string str;
int len;

void dfs(int cnt, string s) {
	if (cnt == len) {
		cout << s << '\n';
		return;
	}

	for (int i = 0; i < len; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		dfs(cnt + 1, s + str[i]);
		visit[i] = false;
	}
}

void func(int tc) {
	cout << "Case # " << tc << ":\n";
	for (int i = 0; i < len; i++) {
		visit[i] = true;
		string s = "";
		dfs(1, s + str[i]);
		visit[i] = false;
	}
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}