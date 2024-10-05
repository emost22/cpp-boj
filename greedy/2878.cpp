#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

ll list[MAX];
ll N, M, sum;

void func() {
	sort(list, list + N);

	sum -= M;
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ll tmp = min(list[i], sum / (N - (ll)i));
		ret += (tmp * tmp);
		sum -= tmp;
	}
	cout << ret << '\n';
}

void input() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		sum += list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}