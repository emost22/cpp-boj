#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N, K;

void func() {
	if (N == 1) {
		cout << "1\n";
		return;
	}

	sort(list, list + N);
	for (int i = 1; i < N; i++) {
		if (list[i - 1] + list[i] > K) {
			cout << i << '\n';
			return;
		}
	}
	
	cout << N << '\n';
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