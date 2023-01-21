#include <iostream>
#define MAX 1001
using namespace std;

typedef struct Point {
	int x;
	int y;
	int z;
}Point;

Point list[MAX];
int N, K;

void func() {
	int ret = 1;
	for (int i = 1; i <= N; i++) {
		if (i == K) continue;
		if (list[K].x != list[i].x) {
			ret += (list[K].x < list[i].x);
			continue;
		}
		if (list[K].y != list[i].y) {
			ret += (list[K].y < list[i].y);
			continue;
		}
		if (list[K].z != list[i].z) {
			ret += (list[K].z < list[i].z);
		}
	}

	cout << ret << '\n';
}

void input() {
	int idx, x, y, z;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> idx >> x >> y >> z;
		list[idx] = { x,y,z };
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}