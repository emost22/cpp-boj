#include <iostream>
#define MAX 10
using namespace std;

int list[MAX];
int N;

int pow(int x, int t) {
	int ret = 1;
	while (t--) {
		ret *= x;
	}

	return ret;
}

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += pow(list[i] / 10, list[i] % 10);
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