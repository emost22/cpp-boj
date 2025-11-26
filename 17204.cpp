#include <iostream>
#define MAX 150
using namespace std;

int list[MAX];
bool visit[MAX];
int N, K;

void func() {
	int ret = 0;
	for (int i = 0; ; i = list[i], ret++) {
		if (i == K) {
			cout << ret << '\n';
			return;
		}

		if (visit[i]) {
			cout << "-1\n";
			return;
		}
		visit[i] = true;
	}
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