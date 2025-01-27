#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int list[MAX];
int R, C, N;

void func() {
	sort(list, list + N);
	
	int* h = new int[C] {0, };
	int idx = 0;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (h[idx] >= list[i]) continue;
		if (ret == R * C) break;

		ret++;
		h[idx] = list[i];
		idx = (idx + 1) % C;
	}

	cout << ret << '\n';
}

void input() {
	cin >> R >> C >> N;
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