#include <iostream>
#define MAX_N 100
#define MAX_M 2000001
using namespace std;

int list[MAX_N];
bool chk[MAX_M];
int N, M;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (chk[list[i]]) continue;
		for (int j = list[i]; j <= M; j += list[i]) {
			if (chk[j]) continue;
			chk[j] = true;
			ret++;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
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