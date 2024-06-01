#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);
	for (int i = 0; i < N; i++) {
		cout << list[i] << ' ';
	}
	cout << '\n';
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