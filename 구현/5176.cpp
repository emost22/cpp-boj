#include <iostream>
#include <cstring>
#define MAX 501
using namespace std;

bool visit[MAX];
int N, M;
int ret;

void func() {
	cout << ret << '\n';
	memset(visit, false, sizeof(visit));
	ret = 0;
}

void input() {
	int x;
	cin >> N >> M;
	while (N--) {
		cin >> x;
		ret += visit[x];
		visit[x] = true;
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