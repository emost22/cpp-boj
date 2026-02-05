#include <iostream>
using namespace std;

const int s[] = { 13,7,5,3,3,2 };
int list[2][6];

void func() {
	const char* ret[] = { "cocjr0208", "ekwoo" };

	int idx = 0;
	int mx = 0;
	for (int i = 0; i < 2; i++) {
		int score = i;
		for (int j = 0; j < 6; j++) {
			score += (list[i][j] * s[j]);
		}

		if (mx <= score) {
			mx = score;
			idx = i;
		}
	}

	cout << ret[idx] << '\n';
}

void input() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}