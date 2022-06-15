#include <iostream>
#define MAX 101
using namespace std;

int a[MAX][MAX], b[MAX][MAX];
int N, M;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << a[i][j] + b[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> b[i][j];
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