#include <iostream>
#include <algorithm>
#define MAX 300001
using namespace std;
typedef long long ll;

ll list[MAX];
int N, K;

void func() {
	sort(list, list + N);
	
	ll ret = list[N - 1];
	K--;
	int l = 0;
	int r = N - 2;
	while (K > 1) {
		ret += (list[r--] - list[l++]);
		K -= 2;
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