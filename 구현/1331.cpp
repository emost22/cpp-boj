#include <iostream>
#include <string>
#include <algorithm>
#define MAX 6
using namespace std;

bool visit[MAX][MAX];
string list[MAX * MAX];

bool isPossibleMove(int px, int py, int x, int y) {
	return (abs(px - x) == 1 && abs(py - y) == 2) || (abs(px - x) == 2 && abs(py - y) == 1);
}

void func() {
	int px = list[0][0] - 'A';
	int py = list[0][1] - '1';
	visit[px][py] = true;
	for (int i = 1; i < MAX * MAX; i++) {
		int x = list[i][0] - 'A';
		int y = list[i][1] - '1';
		if (visit[x][y] || !isPossibleMove(px, py, x, y)) {
			cout << "Invalid\n";
			return;
		}

		visit[x][y] = true;
		px = x;
		py = y;
	}

	if (isPossibleMove(px, py, list[0][0] - 'A', list[0][1] - '1')) cout << "Valid\n";
	else cout << "Invalid\n";
}

void input() {
	for (int i = 0; i < MAX * MAX; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}