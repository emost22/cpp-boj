#include <iostream>
#define MAX 1000001
using namespace std;

int list[MAX];
int ret[MAX];
int N;

void func() {
	int pre = -1;
	for (int i = N; i >= 0; i--) {
		ret[i] = pre;
		if (list[i - 1] != list[i]) {
			pre = i;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ret[i] << ' ';
	}
	cout << '\n';
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