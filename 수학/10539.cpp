#include <iostream>
#define MAX 101
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	ll sum = 0;
	for (ll i = 1; i <= N; i++) {
		list[i] = list[i] * i - sum;
		sum += list[i];
		cout << list[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
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