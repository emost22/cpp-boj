#include <iostream>
#define MAX 1000001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	ll ret = 0;
	for (int i = 1; i < N; i++) {
		ret += ((list[i] - list[i - 1]) * (list[i] - list[i - 1]));
	}
	cout << ret << '\n';
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