#include <iostream>
#define MAX 5001
using namespace std;

int list[MAX];
bool chk[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 1; i < N; i++) {
		if (chk[i]) continue;
		ret++;

		int pre = list[i];
		int diff = list[i] - 1;
		for (int j = i + 1; j < N; j++) {
			if (list[j] - pre != diff) continue;
			chk[j] = true;
			pre = list[j];
		}
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