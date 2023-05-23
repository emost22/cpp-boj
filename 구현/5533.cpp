#include <iostream>
#include <cstring>
#define MAX 201
using namespace std;

int list[MAX][3];
int cnt[MAX], ret[MAX];
int N;

void func() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			cnt[list[j][i]]++;
		}

		for (int j = 0; j < N; j++) {
			if (cnt[list[j][i]] > 1) continue;

			ret[j] += list[j][i];
		}
		memset(cnt, 0, sizeof(cnt));
	}

	for (int i = 0; i < N; i++) {
		cout << ret[i] << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i][0] >> list[i][1] >> list[i][2];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}