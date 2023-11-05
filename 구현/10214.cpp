#include <iostream>
#define MAX 9
using namespace std;

int ret[2];

void func() {
	cout << (ret[0] > ret[1] ? "Yonsei\n" : ret[0] == ret[1] ? "Draw\n" : "Korea\n");
}

void input() {
	int x, y;
	ret[0] = 0;
	ret[1] = 0;
	for (int i = 0; i < MAX; i++) {
		cin >> x >> y;
		ret[0] += x;
		ret[1] += y;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}