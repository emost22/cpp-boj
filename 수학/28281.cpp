#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

ll list[MAX];
ll X;
int N;

void func() {
	ll ret = 1e12;
	for (int i = 1; i < N; i++) {
		ret = min(ret, list[i - 1] * X + list[i] * X);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> X;
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