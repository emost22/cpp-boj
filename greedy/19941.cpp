#include <iostream>
#include <string>
#define MAX 20000
using namespace std;

string str;
bool visit[MAX];
int N, K;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'H') continue;

		for (int j = i - K; j <= i + K && j < N; j++) {
			if (j < 0) continue;
			if (str[j] == 'P') continue;
			if (visit[j]) continue;

			visit[j] = true;
			ans++;
			break;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> K >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}