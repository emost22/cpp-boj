#include <iostream>
#define MAX 2001
using namespace std;

int list[MAX];
int N, K;

void func() {
	int ret = 0;
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (list[1] < list[i]) {
			ret += (list[i] - list[1]);
			cnt++;
		}
	}
	cout << ret << ' ' << cnt << '\n';
}

void input() {
	cin >> N >> K;
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