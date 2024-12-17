#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

vector<int> v[MAX];
int b[MAX], ret[MAX];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 4; j++) {
			if (b[i] & (1 << j)) continue;
			ret[i] = j + 1;
			for (auto next : v[i]) {
				b[next] |= (1 << j);
			}
			break;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ret[i];
	}
	cout << '\n';
}

void input() {
	int x, y;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}