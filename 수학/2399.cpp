#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	ll ret = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			ret += abs(list[i] - list[j]);
		}
	}
	
	cout << (ret << 1) << '\n';
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