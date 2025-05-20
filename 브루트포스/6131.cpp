#include <iostream>
#define MAX 500
#define FOR(i, s) for (int i = s; i <= MAX; i++)
using namespace std;

int N;

void func() {
	int ret = 0;
	FOR(b, 1) {
		FOR(a, b + 1) {
			ret += (b * b + N == a * a);
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}