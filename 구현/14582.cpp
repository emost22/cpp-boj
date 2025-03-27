#include <iostream>
#define MAX 9
using namespace std;

int list[2][MAX];

void func() {
	int x = 0;
	int y = 0;
	bool flag = false;
	for (int i = 0; i < MAX; i++) {
		x += list[0][i];
		if (x > y) flag = true;
		y += list[1][i];
	}

	if (x < y && flag) cout << "Yes\n";
	else cout << "No\n";
}

void input() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < MAX; j++) {
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