#include <iostream>
using namespace std;

int N, W, H;

void func() {
	int len = W * W + H * H;
	int x;
	while (N--) {
		cin >> x;
		if (x * x <= len) {
			cout << "DA\n";
		}
		else {
			cout << "NE\n";
		}
	}
}

void input() {
	cin >> N >> W >> H;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}