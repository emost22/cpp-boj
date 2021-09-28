#include <iostream>
#include <string>
using namespace std;

string list[100];
int N, row, col;

void func() {
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		bool flag = false;
		for (int j = 0; j < N; j++) {
			if (list[i][j] == '.') {
				cnt++;
				if (cnt == 2) {
					if (!flag) row++;
					cnt = 0;
					flag = true;
				}
			}
			else {
				flag = false;
				cnt = 0;
			}
		}
	}

	for (int j = 0; j < N; j++) {
		int cnt = 0;
		bool flag = false;
		for (int i = 0; i < N; i++) {
			if (list[i][j] == '.') {
				cnt++;
				if (cnt == 2) {
					if (!flag) col++;
					cnt = 0;
					flag = true;
				}
			}
			else {
				flag = false;
				cnt = 0;
			}
		}
	}

	cout << row << ' ' << col << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
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