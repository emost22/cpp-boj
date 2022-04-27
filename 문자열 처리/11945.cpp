#include <iostream>
#include <string>
#define MAX 11
using namespace std;

string list[MAX];
int N, M;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--) {
			cout << list[i][j];
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
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