#include <iostream>
#define MAX 1001
using namespace std;

int list[MAX][MAX];
int ret[MAX];
int N;

void func() {
	ret[1] = (list[1][2] + list[1][3] - list[2][3]) >> 1;
	cout << ret[1];
	for (int i = 2; i <= N; i++) {
		ret[i] = list[1][i] - ret[1];
		cout << ' ' << ret[i];
	}
	cout << '\n';
}

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
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