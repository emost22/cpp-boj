#include <iostream>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, K, x, y;

int getDis(int sx, int sy, int ex, int ey) {
	return (ex - sx) * (ex - sx) + (ey - sy) * (ey - sy);
}

void func() {
	K *= K;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (K < getDis(x, y, list[i].first, list[i].second));
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> K >> x >> y;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}