#include <iostream>
using namespace std;

pair<int, int> position[26];
int ques[26];
int rows[5], cols[5], cross[2];

void func() {
	int ans = 0;
	for (int t = 1; t <= 25; t++) {
		int x = position[ques[t]].first;
		int y = position[ques[t]].second;

		rows[x]++;
		cols[y]++;
		if (x == y) {
			cross[0]++;
			if (cross[0] == 5) ans++;
		}
		if (x + y == 4) {
			cross[1]++;
			if (cross[1] == 5) ans++;
		}

		if (rows[x] == 5) ans++;
		if (cols[y] == 5) ans++;

		if (ans >= 3) {
			cout << t << '\n';
			return;
		}
	}
}

void input() {
	int x;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> x;
			position[x].first = i;
			position[x].second = j;
		}
	}

	for (int i = 1; i <= 25; i++) cin >> ques[i];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}