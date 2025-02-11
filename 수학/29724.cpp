#include <iostream>
using namespace std;

int N;

void func() {
	int w, h, l;
	char c;
	int g = 0;
	int value = 0;
	while (N--) {
		cin >> c >> w >> h >> l;
		if (c == 'A') {
			int tmp = (w / 12) * (h / 12) * (l / 12);
			g += (1000 + 500 * tmp);
			value += (4000 * tmp);
		}
		else {
			g += 6000;
		}
	}

	cout << g << '\n' << value << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}