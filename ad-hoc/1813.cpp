#include <iostream>
#define MAX 51
using namespace std;

int cnt[MAX];
int N;

void func() {
	for (int i = MAX - 1; i >= 0; i--) {
		if (cnt[i] == i) {
			cout << i << '\n';
			return;
		}
	}
	cout << "-1\n";
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		cnt[x]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}