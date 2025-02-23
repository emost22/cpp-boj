#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int N, M, K;

void func() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] != 'R') continue;

		cnt++;
		for (int j = i - 1; j >= max(0, i - K); j--) {
			if (str[j] == 'R' || str[j] == 'r') break;
			str[j] = 'r';
			cnt++;
		}

		for (int j = i + 1; j <= min(N - 1, i + K); j++) {
			if (str[j] == 'R') continue;
			str[j] = 'r';
			cnt++;
		}
	}

	if (cnt <= M) cout << "Yes\n";
	else cout << "No\n";
}

void input() {
	cin >> N >> M >> K >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}