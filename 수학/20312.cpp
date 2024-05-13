#include <iostream>
#define MAX 500001
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	ll ret = 0;
	ll prev = 0;
	for (int i = 1; i < N; i++) {
		prev = ((prev + 1) * list[i]) % MOD;
		ret = (ret + prev) % MOD;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i < N; i++) {
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