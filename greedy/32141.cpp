#include <iostream>
#define MAX 1000001
using namespace std;

int list[MAX];
int N, H;

void func() {
	int ret = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += list[i];
		ret++;
		if (sum >= H) {
			cout << ret << '\n';
			return;
		}
	}
	cout << "-1\n";
}

void input() {
	cin >> N >> H;
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