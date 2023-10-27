#include <iostream>
#define MAX 51
using namespace std;

int list[MAX];
int N;

void func(int tc) {
	int ret = 0;
	for (int i = 1; i < N; i++) {
		if (list[i - 1] >= list[i]) {
			ret++;
		}
	}

	cout << "Case #" << tc << ": " << ret << '\n';
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

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}