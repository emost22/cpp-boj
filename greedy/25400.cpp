#include <iostream>
#define MAX 250001
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	int now = 1;
	for (int i = 0; i < N; i++) {
		if (now == list[i]) {
			now++;
			continue;
		}

		ret++;
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