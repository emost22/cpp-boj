#include <iostream>
#define MAX 100
using namespace std;

int list[MAX];
int N;

void func() {
	int now = 0;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (now + list[i] < 30) {
			ret++;
			now += list[i];
		}
		else {
			if (30 - now >= ((list[i] + 1) >> 1)) ret++;
			now = 0;
		}
	}

	cout << ret << '\n';
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