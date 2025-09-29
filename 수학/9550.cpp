#include <iostream>
#define MAX 100
using namespace std;

int list[MAX];
int N, K;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[i] / K);
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

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}