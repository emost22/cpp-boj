#include <iostream>
#define MAX 100
using namespace std;

int N;

void func() {
	int list[4] = { 25,10,5,1 };
	int ret[4] = { 0, };
	int x = MAX - N;
	for (int i = 0; i < 4; i++) {
		ret[i] = x / list[i];
		x -= (list[i] * ret[i]);
	}

	for (auto r : ret) {
		cout << r << ' ';
	}
	cout << '\n';
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