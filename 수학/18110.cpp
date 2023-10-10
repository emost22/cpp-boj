#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 300001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);
	int cnt = round((double)N * 0.15);
	int ret = 0;
	for (int i = cnt; i < N - cnt; i++) {
		ret += list[i];
	}

	if (!(N - cnt - cnt)) cout << "0\n";
	else cout << round((double)ret / (double)(N - cnt - cnt)) << '\n';
}

void input() {
	cin >> N;
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