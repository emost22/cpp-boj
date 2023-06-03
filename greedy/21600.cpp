#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	int h = 0;
	for (int i = 1; i <= N; i++) {
		if (h + 1 <= list[i]) {
			h++;
			ret = max(ret, h);
		}
		else {
			h = list[i];
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
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