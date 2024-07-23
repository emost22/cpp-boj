#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int cnt[MAX];
int N, M;

void func() {
	int type, x;
	while (M--) {
		cin >> type >> x;
		if (type == 1) {
			if (cnt[x] > 1) cout << "yes\n";
			else cout << "no\n";
		}
		else cout << "yes\n";
	}
}

void input() {
	int u, v;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		cnt[u]++;
		cnt[v]++;
	}
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}