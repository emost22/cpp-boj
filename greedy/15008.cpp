#include <iostream>
#include <algorithm>
#define MAX 16
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});

	int f = 0;
	int s = 0;
	for (int i = 0; i < N; i += 2) {
		f += list[i];
		if (i + 1 < N) s += list[i + 1];
	}

	cout << f << ' ' << s << '\n';
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