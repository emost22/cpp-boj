#include <iostream>
#include <string>
#define MAX 51
using namespace std;

string list[MAX];
string str;
int R, N;

int getScore(char x, char y) {
	if (x == y) return 1;
	if (x == 'S' && y == 'P') return 2;
	if (x == 'P' && y == 'R') return 2;
	if (x == 'R' && y == 'S') return 2;
	return 0;
}

void func() {
	int score = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < R; j++) {
			score += getScore(str[j], list[i][j]);
		}
	}

	int maxScore = 0;
	for (int i = 0; i < R; i++) {
		int s = 0;
		int p = 0;
		int r = 0;
		for (int j = 0; j < N; j++) {
			s += getScore('S', list[j][i]);
			p += getScore('P', list[j][i]);
			r += getScore('R', list[j][i]);
		}

		maxScore += max(max(s, p), r);
	}

	cout << score << '\n' << maxScore << '\n';
}

void input() {
	cin >> R >> str >> N;
	for (int i = 0; i < N; i++) {
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