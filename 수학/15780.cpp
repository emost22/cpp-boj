#include <iostream>
#define MAX 100
using namespace std;

int list[MAX];
int N, K;

void func() {
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		cnt += ((list[i] + 1) >> 1);
	}

	if (cnt >= N) cout << "YES\n";
	else cout << "NO\n";
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
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