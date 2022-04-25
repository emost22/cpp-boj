#include <iostream>
#include <string>
#define MAX 101
using namespace std;

string list[MAX];
int N;

void func() {
	if (list[0][0] != list[0][list[0].size() - 1]) {
		cout << "0\n";
		return;
	}

	char x = list[0][0];
	for (int i = 1; i < N; i++) {
		if (x != list[i][0] || x != list[i][list[i].size() - 1]) {
			cout << "0\n";
			return;
		}
	}

	cout << "1\n";
}

void input() {
	cin >> N;
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