#include <iostream>
#include <algorithm>
#define MAX 40001
using namespace std;

int list[MAX];
int N, X, Y;

void func() {
	int ret = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int tmp = list[i] / X;
		ret += tmp;
		sum += (list[i] - X * tmp - min(list[i] - X * tmp, (Y - X) * tmp));
	}

	cout << ret << '\n' << sum << '\n';
}

void input() {
	cin >> N >> X >> Y;
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