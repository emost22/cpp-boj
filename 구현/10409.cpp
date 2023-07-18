#include <iostream>
#define MAX 51
using namespace std;

int list[MAX];
int N, T;

void func() {
	int ret = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += list[i];
		if (sum > T) break;
		ret++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> T;
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