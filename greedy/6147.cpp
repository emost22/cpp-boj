#include <iostream>
#include <algorithm>
#define MAX 20001
using namespace std;

int list[MAX];
int N, B;

void func() {
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});

	int ret = 0;
	int sum = 0;
	for (int i = 0; i < N && sum < B; i++, ret++) {
		sum += list[i];
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> B;
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