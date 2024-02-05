#include <iostream>
#define MAX 5000000
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 1;
	for (int i = 1; i < N; i++) {
		ret += list[i] >= list[i - 1];
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