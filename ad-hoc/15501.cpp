#include <iostream>
#define MAX 1000001
using namespace std;

int list[MAX];
int ret[MAX];
int direct[2] = { 1,-1 };
int N;

void func() {
	int idx = 0;
	int d = 0;
	for (int i = 0; i < N; i++) {
		if (ret[i] == list[0]) {
			idx = i;
			if (ret[(i + 1) % N] == list[1]) d = 0;
			else  d = 1;
			break;
		}
	}

	int cnt = 0;
	while (cnt < N) {
		if (list[cnt] != ret[idx]) {
			cout << "bad puzzle\n";
			return;
		}

		idx = (idx + N + direct[d]) % N;
		cnt++;
	}

	cout << "good puzzle\n";
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> ret[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}