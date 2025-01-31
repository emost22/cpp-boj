#include <iostream>
using namespace std;

int N, M;

void func() {
	if (N <= M) cout << "Yes\n";
	else cout << "No\n";
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
	}

	for (int i = 0; i < M; i++) {
		cin >> x;
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