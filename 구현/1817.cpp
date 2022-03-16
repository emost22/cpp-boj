#include <iostream>
#define MAX 51
using namespace std;

int list[MAX];
int N, M;

void func() {
	int ans = N ? 1 : 0;
	int m = M;
	for (int i = 0; i < N; i++) {
		if (list[i] > m) {
			m = M;
			ans++;
		}
		
		m -= list[i];
	}

	cout << ans << '\n';
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