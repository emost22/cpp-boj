#include <iostream>
#define MAX 1000002
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 1; i < N; i++) {
		ret += (list[i - 1] >= list[i]);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	list[N++] = list[0];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}