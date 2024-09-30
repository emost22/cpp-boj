#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int weight[7] = { 100,50,20,10,5,2,1 };
int list[MAX];
int N;

void func() {
	int l = list[0];
	int r = list[1];
	for (int i = 2; i < N; i++) {
		if (l <= r) {
			l += list[i];
		}
		else {
			r += list[i];
		}
	}

	int sub = abs(r - l);
	int ret = 0;
	for (int i = 0; i < 7; i++) {
		ret += (sub / weight[i]);
		sub %= weight[i];
	}
	cout << ret << '\n';
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