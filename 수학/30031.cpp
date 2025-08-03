#include <iostream>
#define OK 136
#define FK 142
#define TK 148
#define MAX 100
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (OK == list[i]) ret += 1000;
		else if (FK == list[i]) ret += 5000;
		else if (TK == list[i]) ret += 10000;
		else ret += 50000;
	}
	cout << ret << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i] >> x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}