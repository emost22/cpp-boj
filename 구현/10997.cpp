#include <iostream>
#define MAX 101
using namespace std;

char list[MAX * 4][MAX * 4];
int direct[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int N;

void func() {
	if (N == 1) {
		cout << "*\n";
		return;
	}

	int sz = 1 + (N - 1) * 4;
	int x = (sz + 2) / 2 + 2;
	int y = sz / 2 + 1;
	int idx = 0;
	int cnt = 2;
	list[x][y] = '*';
	while (1) {
		bool flag = false;
		for (int t = 0; t < 2; t++) {
			for (int i = 0; i < cnt; i++) {
				x += direct[idx][0];
				y += direct[idx][1];
				if (y > sz) {
					flag = true;
					break;
				}
				list[x][y] = '*';
			}
			if (flag) break;
			idx = (idx + 1) % 4;
		}
		if (flag) break;
		cnt += 2;
	}

	for (int i = 1; i <= sz + 2; i++) {
		for (int j = 1; j <= sz; j++) {
			if (i == 2 && j > 1) break;
			if (list[i][j]) cout << list[i][j];
			else cout << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}