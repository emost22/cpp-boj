#include <iostream>
#define MAX 51
using namespace std;

typedef struct Circle {
	int x, y, r;
}Circle;

Circle list[MAX];
int N, sx, sy, ex, ey;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int dis1 = (list[i].x - sx) * (list[i].x - sx) + (list[i].y - sy) * (list[i].y - sy);
		int dis2 = (list[i].x - ex) * (list[i].x - ex) + (list[i].y - ey) * (list[i].y - ey);

		int r = list[i].r * list[i].r;
		if (dis1 > r == dis2 > r) continue;
		ans++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> sx >> sy >> ex >> ey >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].x >> list[i].y >> list[i].r;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}