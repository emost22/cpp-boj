#include <iostream>
#define MAX 33
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = list[0];
	for (int i = 1; i < N; i++) {
		if (list[i - 1] + 1 == list[i]) continue;

		ret += list[i];
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