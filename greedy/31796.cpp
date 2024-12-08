#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	int ret = 1;
	int pre = list[0];
	for (int i = 1; i < N; i++) {
		if ((pre << 1) > list[i]) continue;
		ret++;
		pre = list[i];
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