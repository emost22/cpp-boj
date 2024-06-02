#include <iostream>
#include <algorithm>
#define MAX 1001
#define INF 200
using namespace std;

int list[MAX];
int N, P;

void func() {
	sort(list, list + N);

	int ret = 0;
	int now = P;
	for (int i = 0; i < N; i++) {
		if (now >= INF) break;
		now += list[i];
		ret++;
	}
	
	cout << ret << '\n';
}

void input() {
	cin >> P >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}