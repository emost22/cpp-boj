#include <iostream>
#include <string>
using namespace std;

const int index[][2] = { {0,1},{0,2},{0,3},{1,2},{1,3},{2,3} };
string str;

void func() {
	int list[] = { 1,0,0,2 };
	for (auto x : str) {
		swap(list[index[x - 'A'][0]], list[index[x - 'A'][1]]);
	}

	for (int i = 0; i < 4; i++) {
		if (list[i] != 1) continue;
		cout << i + 1 << '\n';
	}

	for (int i = 0; i < 4; i++) {
		if (list[i] != 2) continue;
		cout << i + 1 << '\n';
	}
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}