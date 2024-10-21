#include <iostream>
#define MAX 100001
using namespace std;

int list[MAX];
int N, K;

void func() {
	int ret = 0;
	int t = 0;
	for (int i = 0; i < N; i++) {
		if (t < list[i]) {
			t = list[i] + K;
			ret++;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
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