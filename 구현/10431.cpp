#include <iostream>
#define MAX 20
using namespace std;

int list[MAX];
int t;

void func() {
	int ret = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < i; j++) {
			ret += (list[i] < list[j]);
		}
	}
	cout << t << ' ' << ret << '\n';
}

void input() {
	cin >> t;
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
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