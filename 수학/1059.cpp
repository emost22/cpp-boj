#include <iostream>
#include <algorithm>
#define MAX 51
using namespace std;

int list[MAX];
int N, M;

void func() {
	sort(list, list + N + 1);
	int l = -1;
	int r = -1;
	for (int i = 0; i < N; i++) {
		if (list[i] < M && M < list[i + 1]) {
			l = list[i];
			r = list[i + 1];
			break;
		}
	}

	if (l == -1) cout << "0\n";
	else cout << (r - M) * (M - l) - 1 << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}