#include <iostream>
using namespace std;

int list[1000];
int N, M, L;

void func() {
	int idx = 0;
	for (int t = 0; ; t++) {
		list[idx]++;
		if (list[idx] == M) {
			cout << t << '\n';
			break;
		}

		if (list[idx] % 2) idx = (idx + L) % N;
		else idx = (idx - L + N) % N;
	}
}

void input() {
	cin >> N >> M >> L;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	input();
	func();

	return 0;
}