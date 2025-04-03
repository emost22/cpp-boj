#include <iostream>
#define MAX_K 2556
#define MAX_V 556
using namespace std;

int list[MAX_K][MAX_V];
int K, V;

void func(int tc) {
	cout << "Case #" << tc << ": " << list[K][V] << '\n';
}

void input() {
	cin >> K >> V;
}

void init() {
	int p = 1;
	int t = 6;
	for (int j = 0; j < MAX_V; j++) {
		list[j][j] = (j + 1) * (j + 1) * (j + 1);
		for (int i = j + 1; i < MAX_K; i++) {
			list[i][j] = list[i - 1][j] + p;
		}
		p += t;
		t += 6;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}