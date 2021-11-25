#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

int alpha = (1 << 26) - 1;
int list[MAX];
int N, M;

void print() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if ((list[i] & alpha) == list[i]) {
			ans++;
		}
	}

	cout << ans << '\n';
}

void func() {
	int type;
	char x;
	while (M--) {
		cin >> type >> x;
		if (type == 1) {
			alpha &= ~(1 << (x - 'a'));
		}
		else {
			alpha |= (1 << (x - 'a'));
		}

		print();
	}
}

void input() {
	string str;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			int x = 1 << (str[j] - 'a');

			list[i] |= x;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}