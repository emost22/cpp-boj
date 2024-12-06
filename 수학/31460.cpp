#include <iostream>
#include <string>
#define MAX 10001
using namespace std;

string list[MAX];
int N;

void init() {
	list[2] = "1";
	list[3] = "12";
	for (int i = 4; i < MAX; i++) {
		list[i] = list[i - 1] + "2";
	}
}

void func() {
	if (N == 1) cout << "0\n";
	else cout << list[N] << "1\n";
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}