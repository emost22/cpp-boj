#include <iostream>
#define MAX 100000
using namespace std;

int list[MAX];
int N;

void func() {
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		sum += list[i];
		cnt += (list[i] >> 1);
	}

	if (sum % 3 || sum / 3 > cnt) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
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