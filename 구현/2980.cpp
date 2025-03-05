#include <iostream>
#define MAX 101
using namespace std;

typedef struct Node {
	int d, r, g;
}Node;

Node list[MAX];
int N, L;

void func() {
	int ret = 0;
	int now = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[i].d - now);
		now = list[i].d;

		int t = ret % (list[i].r + list[i].g);
		if (t < list[i].r) {
			ret += (list[i].r - t);
		}
	}

	cout << ret + L - now << '\n';
}

void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> list[i].d >> list[i].r >> list[i].g;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}