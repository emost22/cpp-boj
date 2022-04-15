#include <iostream>
#include <string>
#include <algorithm>
#define MAX 21
using namespace std;

string str[MAX], ans[MAX];
int N, M;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M * 2; j++) {
			if (str[i][j / 2] != ans[i][j]) {
				cout << "Not Eyfa\n";
				return;
			}
		}
	}

	cout << "Eyfa\n";
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> ans[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}