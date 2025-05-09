#include <iostream>
#define MAX 101
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret++;
		if (ret != list[i]) continue;
		ret++;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
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