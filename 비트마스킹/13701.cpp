#include <iostream>
#define MAX 1 + (1 << 20)
using namespace std;

int list[MAX];

void func(int N) {
	int x = N >> 5;
	int y = N % 32;
	int z = (1 << y);

	if (list[x] & z) return;
	list[x] |= z;
	cout << N << ' ';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	while (cin >> N) {
		func(N);
	}

	return 0;
}