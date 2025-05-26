#include <iostream>
#define MAX 1001
using namespace std;

bool chk[MAX];
int list[MAX];
int N, M;

void func() {
	int ret = 0;
	for (int i = 0; i < M; i++) {
		if (chk[list[i]]) continue;
		for (int j = list[i]; j <= N; j += list[i]) {
			if (chk[j]) continue;
			chk[j] = true;
			ret += j;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
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