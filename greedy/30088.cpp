#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	sort(list, list + N);
	
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[i] * (N - i));
	}

	cout << ret << '\n';
}

void input() {
	int M;
	ll x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		while (M--) {
			cin >> x;
			list[i] += x;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}