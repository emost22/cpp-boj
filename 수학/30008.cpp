#include <iostream>
#define MAX 400
using namespace std;

int list[MAX];
int N, K;

int getGrade(int x) {
	if (x <= 4) return 1;
	if (x <= 11) return 2;
	if (x <= 23) return 3;
	if (x <= 40) return 4;
	if (x <= 60) return 5;
	if (x <= 77) return 6;
	if (x <= 89) return 7;
	if (x <= 96) return 8;
	else return 9;
}

void func() {
	for (int i = 0; i < K; i++) {
		cout << getGrade(list[i] * 100 / N) << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
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