#include <iostream>
#include <string>
#define MAX 1001
using namespace std;

string str;
string list[MAX];
int N, M;

void func() {
	for (int i = 0; i < M; i++) {
		int idx = 0;
		int len = list[i].size();
		for (int j = 0; j < len; j++) {
			if (list[i][j] == str[idx]) idx++;
			if (idx == N) break;
		}

		if (idx == N) cout << "true\n";
		else cout << "false\n";
	}
}

void input() {
	cin >> N >> M >> str;
	for (int i = 0; i < M; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}