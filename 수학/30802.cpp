#include <iostream>
#define MAX 6
using namespace std;

int list[MAX];
int N, T, P;

void func() {
	int ret = 0;
	for (int i = 0; i < MAX; i++) {
		ret += (list[i] / T) + (list[i] % T != 0);
	}
	cout << ret << '\n' << N / P << ' ' << N % P << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
	}
	cin >> T >> P;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}