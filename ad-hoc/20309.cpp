#include <iostream>
#define MAX 300001
using namespace std;

int list[MAX];
int N;

void func() {
	for (int i = 0; i < N; i++) {
		if (list[i] & 1 && i & 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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