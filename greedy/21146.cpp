#include <iostream>
using namespace std;

int sum;
int N, k;

void func() {
	cout << fixed; cout.precision(4);
	cout << (double)(sum + (N - k) * (-3)) / (double)N << ' ' << (double)(sum + (N - k) * 3) / (double)N << '\n';
}

void input() {
	int x;
	cin >> N >> k;
	for (int i = 0; i < k; i++) {
		cin >> x;
		sum += x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}