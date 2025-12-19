#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret = max(ret, list[i] - (N - i));
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