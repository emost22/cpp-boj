#include <iostream>
#include <algorithm>
using namespace std;

int cnts[4];
int N;

void func() {
	int tmp = min(cnts[0], cnts[3]);
	cnts[0] -= tmp;
	cnts[3] -= tmp;

	int ret = tmp * 3;
	tmp = min(cnts[1], cnts[2]);
	cnts[1] -= tmp;
	cnts[2] -= tmp;

	ret += (tmp * 3);
	tmp = min(cnts[0], cnts[2]);
	cnts[0] -= tmp;
	cnts[2] -= tmp;
	
	ret += (tmp << 1);
	tmp = min(cnts[1], cnts[3]);
	cnts[1] -= tmp;
	cnts[3] -= tmp;

	ret += (tmp << 1);
	tmp = min(cnts[0], cnts[1]);
	cnts[0] -= tmp;
	cnts[1] -= tmp;

	ret += tmp;
	tmp = min(cnts[2], cnts[3]);
	cnts[2] -= tmp;
	cnts[3] -= tmp;

	ret += tmp;
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