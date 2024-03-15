#include <iostream>
#include <string>
#define MAX 201
using namespace std;

char list[MAX][MAX];
string str;
int N, len;

void func() {
	int idx = 0;
	int M = len / N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (i & 1) list[i][N - j - 1] = str[idx++];
			else list[i][j] = str[idx++];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << list[j][i];
		}
	}
	cout << '\n';
}

void input() {
	cin >> N >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}