#include <iostream>
#define MAX 11
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[i].first * list[i].second);
	}

	cout << ret << " miles\n";
}

void input() {
	int pre = 0;
	cin >> N;
	if (N == -1) exit(0);

	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
		int tmp = list[i].second;
		list[i].second -= pre;
		pre = tmp;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}