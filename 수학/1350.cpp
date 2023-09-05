#include <iostream>
#define MAX 51
using namespace std;
typedef long long ll;

ll list[MAX];
ll K;
int N;

void func() {
	ll cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!(list[i] % K)) cnt += (list[i] / K);
		else cnt += (list[i] / K + 1);
	}

	cout << K * cnt << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}