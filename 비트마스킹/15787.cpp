#include <iostream>
#include <set>
#define MAX 100001
using namespace std;

int list[MAX];
int N, M;

void func() {
	int type, x, y;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			list[x] |= (1 << (y - 1));
		}
		else if (type == 2) {
			cin >> x >> y;
			list[x] &= ~(1 << (y - 1));
		}
		else if (type == 3) {
			cin >> x;
			list[x] &= ~(1 << 19);
			list[x] <<= 1;
		}
		else {
			cin >> x;
			list[x] >>= 1;
		}
	}

	set<int> s;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (s.find(list[i]) != s.end()) continue;
		s.insert(list[i]);
		ans++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}