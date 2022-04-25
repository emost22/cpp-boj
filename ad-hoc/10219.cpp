#include <iostream>
#define MAX 12
using namespace std;

char list[MAX][MAX];
int N, M;

void func() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			cout << list[i][j];
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
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