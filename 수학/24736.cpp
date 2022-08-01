#include <iostream>
#define MAX 5
using namespace std;

int list[MAX];

void input() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> list[j];
		}
		cout << list[0] * 6 + list[1] * 3 + list[2] * 2 + list[3] + list[4] * 2 << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}