#include <iostream>
#define MAX 40001
using namespace std;

int N, M;
int sx, sy, K;

void func() {
	int ex = N;
	int ey = M;
	int tx = K;
	int ty = K;
	
	tx %= (ex * 2);
	ty %= (ey * 2);

	if (tx <= ex - sx) {
		sx += tx;
	}
	else if (tx <= ex - sx + ex) {
		sx = ex - tx + ex - sx;
	}
	else {
		sx = tx - (ex - sx + ex);
	}

	if (ty <= ey - sy) {
		sy += ty;
	}
	else if (ty <= ey - sy + ey) {
		sy = ey - ty + ey - sy;
	}
	else {
		sy = ty - (ey - sy + ey);
	}

	cout << sx << ' ' << sy << '\n';
}

void input() {
	cin >> N >> M >> sx >> sy >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}