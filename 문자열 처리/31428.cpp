#include <iostream>
#define MAX 10001
using namespace std;

char list[MAX];
char x;
int N;

void func() {
	int ret = 0;
	for (auto ch : list) {
		ret += x == ch;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}