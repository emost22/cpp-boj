#include <iostream>
#include <algorithm>
#define MAX 5
using namespace std;

int list[MAX];
int A, B, N;

void func() {
	int ans = abs(A - B);
	for (int i = 0; i < N; i++) {
		ans = min(ans, abs(list[i] - B) + 1);
	}

	cout << ans << '\n';
}

void input() {
	cin >> A >> B >> N;
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