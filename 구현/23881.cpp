#include <iostream>
#define MAX 10000
using namespace std;

int list[MAX];
int N, K;

void func() {
	int cnt = 0;
	for (int i = N - 1; i > 0; i--) {
		int idx = i;
		int mx = list[i];
		for (int j = i - 1; j >= 0; j--) {
			if (list[j] > mx) {
				mx = list[j];
				idx = j;
			}
		}

		if (idx == i) continue;
		cnt++;
		if (cnt == K) {
			cout << list[i] << ' ' << list[idx] << '\n';
			return;
		}

		swap(list[i], list[idx]);
	}

	cout << "-1\n";
}

void input() {
	cin >> N >> K;
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