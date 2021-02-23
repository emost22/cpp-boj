#include <iostream>
using namespace std;

int list[101][101], num[101];
int N;

void print() {
	for (int i = 1; i <= N; i++) {
		cout << num[i] << '\n';
	}
}

void input() {
	int sx, sy, width, height;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sx >> sy >> width >> height;
		for (int x = sx; x < sx + width; x++) {
			for (int y = sy; y < sy + height; y++) {
				if (list[x][y]) {
					num[list[x][y]]--;
				}
				list[x][y] = i;
				num[list[x][y]]++;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	print();

	return 0;
}