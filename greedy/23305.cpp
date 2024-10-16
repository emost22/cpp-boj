#include <iostream>
#define MAX 1000001
using namespace std;

int cnts[MAX];
int N;

void func() {
	int x;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (!cnts[x]) ret++;
		else cnts[x]--;
	}
	cout << ret << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		cnts[x]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}