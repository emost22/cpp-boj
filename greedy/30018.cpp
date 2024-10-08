#include <iostream>
#define MAX 101
using namespace std;

int a[MAX], b[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] >= b[i]) continue;
		ret += (b[i] - a[i]);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}