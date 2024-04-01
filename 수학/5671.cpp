#include <iostream>
#include <vector>
using namespace std;

int N, M;

bool checkDuplicated(int x) {
	vector<bool> visit(10, false);
	while (x) {
		if (visit[x % 10]) return false;
		visit[x % 10] = true;
		x /= 10;
	}
	visit.clear();
	return true;
}

void func() {
	int ret = 0;
	for (int i = N; i <= M; i++) {
		ret += checkDuplicated(i);
	}

	cout << ret << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> N && cin >> M) {
		func();
	}

	return 0;
}