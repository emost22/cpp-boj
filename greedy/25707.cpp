#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	int ret = 0;
	for (int i = 1; i < N; i++) {
		ret += (list[i] - list[i - 1]);
	}
	ret += (list[N - 1] - list[0]);

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