#include <iostream>
#define MAX 1000001
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (!list[i]) continue;
		list[i] = 1 - list[i];
		if (i + 1 <= N) list[i + 1] = 1 - list[i + 1];
		if (i + 2 <= N) list[i + 2] = 1 - list[i + 2];
		ret++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
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