#include <iostream>
using namespace std;

int list[4];
int N;

void init(int t) {
	if (t) {
		list[0] = 1;
		list[1] = 2;
		list[2] = 4;
		list[3] = 3;
	}
	else {
		list[0] = 1;
		list[1] = 3;
		list[2] = 2;
		list[3] = 4;
	}
	
}

void func() {
	init(N % 4 == 2);

	cout << "YES\n";
	int idx = 0;
	while (N--) {
		cout << list[idx] << ' ';
		list[idx] += 4;
		idx = (idx + 1) % 4;
	}
	cout << '\n';
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