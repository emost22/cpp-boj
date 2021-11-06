#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int list[MAX];
int N, M;

void func() {
	int ans = 0;
	int price = 0;
	for (int i = 0; i < M; i++) {
		int next = list[i] * min(N, i + 1);
		if (ans <= next) {
			price = list[i];
			ans = next;
		}
	}

	cout << price << ' ' << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> list[i];
	}
	sort(list, list + M, [](int a, int b) {
		return a > b;
	});
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}