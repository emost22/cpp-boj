#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 1;
	for (int i = 0; i < N; i++) {
		int sum = list[i];
		int cnt = 1;
		for (int j = i + 1; j < N; j++) {
			if (sum < list[j]) continue;
			sum += list[j];
			ret = max(ret, ++cnt);
		}
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