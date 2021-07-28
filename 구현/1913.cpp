#include <iostream>
using namespace std;

int list[1000][1000];
int direct[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int N, K, ansx, ansy;

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << list[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << ansx << ' ' << ansy << '\n';
}

void func() {
	int x = (N + 1) / 2;
	int y = (N + 1) / 2;
	int move = 1;
	int cnt = 0;
	int idx = 0;
	int value = 1;
	list[x][y] = value++;

	while (true) {
		if (list[x][y] == K) {
			ansx = x;
			ansy = y;
		}
		if (x == 1 && y == 1) break;

		x += direct[idx][0];
		y += direct[idx][1];
		cnt++;

		list[x][y] = value++;
		if (cnt == move) {
			if (idx == 1 || idx == 3) move++;
			idx = (idx + 1) % 4;
			cnt = 0;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	func();
	print();

	return 0;
}