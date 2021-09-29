#include <iostream>
#include <algorithm>
using namespace std;

int list[1000];
int N;

void func() {
	if (list[0] != 1) {
		cout << "1\n";
		return;
	}

	int sum = 1;
	for (int i = 1; i < N; i++) {
		if (sum + 1 < list[i]) break;
		sum += list[i];
	}

	cout << sum + 1 << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}