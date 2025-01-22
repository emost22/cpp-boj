#include <iostream>
#include <algorithm>
#define MAX 50001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	int ret = 1e9;
	for (int i = 0; i < N; i++) {
		ret = min(ret, list[i] / (i + 1));
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

	input();
	func();

	return 0;
}