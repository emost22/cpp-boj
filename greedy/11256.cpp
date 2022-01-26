#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
typedef pair<int, int> pi;

int list[MAX];
int N, K;

void func() {
	for (int i = 0; i < N; i++) {
		if (K <= list[i]) {
			cout << i + 1 << '\n';
			return;
		}
		K -= list[i];
	}

	cout << N << '\n';
}

void input() {
	int x, y;
	cin >> K >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		list[i] = x * y;
	}
	
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});
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