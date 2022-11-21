#include <iostream>
#define MAX 30
using namespace std;

int list[MAX];
int N, d, sum;

void func() {
	for (int i = 0; i < N; i++) {
		cout << d * list[i] / sum << '\n';
	}
}

void input() {
	cin >> N >> d;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		sum += list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}