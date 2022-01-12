#include <iostream>
#include <algorithm>
#define MAX 51
using namespace std;

int list[MAX];
int N;

void func() {
	int l = 0;
	int lcnt = 0;
	int r = 0;
	int rcnt = 0;
	for (int i = 1; i <= N; i++) {
		if (l < list[i]) {
			lcnt++;
			l = list[i];
		}
	}

	for (int i = N; i >= 1; i--) {
		if (r < list[i]) {
			rcnt++;
			r = list[i];
		}
	}

	cout << lcnt << '\n' << rcnt << '\n';
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