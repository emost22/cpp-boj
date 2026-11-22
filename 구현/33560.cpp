#include <iostream>
#define MAX 100001
using namespace std;

int list[MAX];
int N;

void gameEnd(int &score, int ret[], int &t, int &diceScore, int &timeFlow) {
	if (score < 35) {

	}
	else if (score < 65) {
		ret[0]++;
	}
	else if (score < 95) {
		ret[1]++;
	}
	else if (score < 125) {
		ret[2]++;
	}
	else {
		ret[3]++;
	}

	score = 0;
	t = 0;
	diceScore = 1;
	timeFlow = 4;
}

void func() {
	int diceScore = 1;
	int timeFlow = 4;
	int ret[4] = { 0,0,0,0 };
	int score = 0;
	int t = 0;
	for (int i = 0; i < N; i++) {
		if (t > 240) {
			gameEnd(score, ret, t, diceScore, timeFlow);
		}

		if (list[i] == 1) {
			gameEnd(score, ret, t, diceScore, timeFlow);
			continue;
		}
		else if (list[i] == 2) {
			if (diceScore > 1) diceScore >>= 1;
			else timeFlow += 2;
		}
		else if (list[i] == 3) {

		}
		else if (list[i] == 4) {
			t += 56;
		}
		else if (list[i] == 5) {
			if (timeFlow > 1) timeFlow--;
		}
		else {
			if (diceScore < 32) diceScore <<= 1;
		}

		t += timeFlow;
		score += diceScore;
	}

	for (auto x : ret) {
		cout << x << '\n';
	}
}

void input() {
	cin >> N;
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