#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;

int list[MAX];
int N;

void func() {
	int status = 0;
	int ret = 1;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (list[i - 1] > list[i]) {
			if (status == -1) cnt++;
			else {
				status = -1;
				cnt = 2;
			}
		}
		else if (list[i - 1] < list[i]) {
			if (status == 1) cnt++;
			else {
				status = 1;
				cnt = 2;
			}
		}
		ret = max(ret, cnt);
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