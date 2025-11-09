#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

char p1[MAX], p2[MAX];
int score[2];
int N;

int findWinner(char x, char y) {
	if (x == 'R' && y == 'P') return 1;
	if (x == 'P' && y == 'S') return 1;
	if (x == 'S' && y == 'R') return 1;
	if (x == 'P' && y == 'R') return 0;
	if (x == 'S' && y == 'P') return 0;
	if (x == 'R' && y == 'S') return 0;
	return -1;
}

void func() {
	for (int i = 0; i < N; i++) {
		int s = findWinner(p1[i], p2[i]);
		if (s == -1) continue;
		score[s]++;
	}

	if (score[0] > score[1]) cout << "Player 1\n";
	else if (score[0] < score[1]) cout << "Player 2\n";
	else cout << "TIE\n";

	memset(score, 0, sizeof(score));
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p1[i] >> p2[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}