#include <iostream>
#include <algorithm>
#define MAX 300001
using namespace std;
typedef long long ll;

ll list[MAX];
int N, K;

void func() {
	sort(list, list + N);
	
	ll ret = 0;
	for (int i = 1; i < N; i++) {
		if (i < K) ret += (list[i] * (ll)i);
		else ret += (list[i] * (ll)K);
	}
	
	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
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